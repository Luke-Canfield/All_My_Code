#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "btree.h"

/********************************************************************
|* RULES
|*
|*  1. Do not access 'node -> subtrees' directly.  Use wrappers (accessor functions) instead.
|*   ┌──────────────────────────┬────────────────────────────────────────────┐
|*   │ Instead of this (▼),     │ Use this (▼).                              │
|*   ╞══════════════════════════╪════════════════════════════════════════════╡
|*   │ node -> subtrees[…]      │ get_subtree(node, subtree_idx)             │
|*   ├──────────────────────────┼────────────────────────────────────────────┤
|*   │ node -> subtrees[…] = …; │ set_subtree(node, subtree_idx, new_subtree)│
|*   ├──────────────────────────┼────────────────────────────────────────────┤
|*   │ &(node -> subtrees[…])   │ get_address_of_subtree(node, subtree_idx   │
|*   └──────────────────────────┴────────────────────────────────────────────┘
|*      ∘ When testing your code, we may modify the wrappers to track which nodes were accessed.
|*      ∘ This applies only to 'node -> subtrees'.  You may access all other fields like usual.
|*
|*  2. Use descriptive names that accurately indicate the variable's type and contents.
|*      ∘ Use 'key_idx' (or 'keyIdx') or 'subtree_idx' (or 'subtreeIdx'), not 'idx', 'i', or 'pos'.
|*      ∘ Use 'copy_of_▒' (or 'copyOf▒') instead of 'temp' if you need to swap two values.
|*      ∘ See code quality standards for other naming conventions.
|*
|*  3. Comment any code that is not self-explanatory.
|*      ∘ See btree_insert.c for examples.
|*
|*  4. Use assertions to document and sanity-check values.
|*      ∘ Ex: Check that indexes are in the expected range.
|*      ∘ Some assertions have already been added to the stub functions below.
|*      ∘ You must add more, as appropriate.  (There is not specific number.)  This is to help you.
|*
|* This is in addition to the requirements in the assignment page.
|*
|* WARNING: There may be penalties for submissions that do not follow these rules.
\*******************************************************************/

bool SUCCESS_DELETE = false;

void merge_subtree_with_next(BTreeNode* parent, int subtree_1_idx) {
	int subtree_2_idx = subtree_1_idx + 1;
	assert(subtree_1_idx >= 0 && subtree_1_idx <= parent -> num_keys);
	assert(subtree_2_idx >= 0 && subtree_2_idx <= parent -> num_keys);

	// Get the children to be merged.
	BTreeNode* subtree_1 = get_subtree(parent, subtree_1_idx);
	BTreeNode* subtree_2 = get_subtree(parent, subtree_1_idx + 1);
	assert(subtree_1 -> num_keys + subtree_2 -> num_keys <= MAX_KEYS);

	int subtree_2_key_idx = 0;
	int total_num_keys = (subtree_1 -> num_keys) + (subtree_2 -> num_keys);
	(subtree_1 -> num_keys)++;
	subtree_1 -> keys[(subtree_1 -> num_keys) - 1] = parent -> keys[subtree_1_idx];
	parent -> keys[subtree_1_idx] = 0;
	for(int i = (subtree_1 -> num_keys) - 1; i < total_num_keys; i++) {
		(subtree_1 -> num_keys)++;
		subtree_1 -> keys[(subtree_1 -> num_keys) - 1] = subtree_2 -> keys[subtree_2_key_idx];
		subtree_2_key_idx++;
		(subtree_2 -> num_keys)--;
	}
	free(subtree_2);
	(parent -> num_keys)--;

}

void shift_key_forward(BTreeNode* parent, int src_subtree_idx) {
	// Move the last key from get_subtree(parent, src_subtree_idx) to the next subtree.
	int dst_subtree_idx = src_subtree_idx + 1;

	assert(src_subtree_idx >= 0 && src_subtree_idx <= parent -> num_keys);
	assert(dst_subtree_idx >= 1 && dst_subtree_idx <= parent -> num_keys);

	BTreeNode* src_subtree = get_subtree(parent, src_subtree_idx);
	BTreeNode* dst_subtree = get_subtree(parent, dst_subtree_idx);
	assert(src_subtree -> num_keys <= MAX_KEYS);      // Assert: source has ≥1 extra node
	assert(dst_subtree -> num_keys <= MAX_KEYS - 1); // Assert: destination has too few

	int last_key_idx = src_subtree -> num_keys - 1;
	if(last_key_idx >= 0) {
		(dst_subtree -> num_keys)++;
		(src_subtree -> num_keys)--;
		for(int i = (dst_subtree -> num_keys) - 1; i > 0; i--) {
			dst_subtree -> keys[i] = dst_subtree -> keys[i - 1];
		}
		dst_subtree -> keys[0] = parent -> keys[src_subtree_idx];
		parent -> keys[src_subtree_idx] = src_subtree -> keys[last_key_idx];

	}
	assert(dst_subtree -> num_keys <= MAX_KEYS);
	
}

void shift_key_backward(BTreeNode* parent, int src_subtree_idx) {
	// Move the first key from get_subtree(parent, src_subtree_idx) to previous subtree.
	int dst_subtree_idx = src_subtree_idx - 1;
	assert(src_subtree_idx >= 1 && src_subtree_idx <= parent -> num_keys);
	assert(dst_subtree_idx >= 0 && dst_subtree_idx <= parent -> num_keys);

	BTreeNode* src_subtree = get_subtree(parent, src_subtree_idx);
	BTreeNode* dst_subtree = get_subtree(parent, dst_subtree_idx);
	assert(src_subtree -> num_keys <= MAX_KEYS);
	assert(dst_subtree -> num_keys <= MAX_KEYS - 1);

	int first_key_idx = 0;
	if(first_key_idx >= 0) {
		(dst_subtree -> num_keys)++;
		dst_subtree -> keys[(dst_subtree -> num_keys) - 1] = parent -> keys[src_subtree_idx - 1];
		parent -> keys[src_subtree_idx - 1] = src_subtree -> keys[first_key_idx];

		for(int i = 0; i < (src_subtree -> num_keys); i++) {
			src_subtree -> keys[i] = src_subtree -> keys[i + 1];
		}
		(src_subtree -> num_keys)--;
	}
	assert(dst_subtree -> num_keys <= MAX_KEYS);

}

KeyLocation get_in_order_predecessor(KeyLocation key_location) {
	// Return the key (with location) for key that would precede this one in an in-order traversal.
	assert(get_subtree(key_location.node, 0) != NULL);  // not a leaf
	KeyLocation predecessor;
	BTreeNode* curr_node = get_subtree(key_location.node, key_location.key_idx);

	// Didn't use compound initializer for predecessor due to readability 
	predecessor.key = query_max(curr_node);
	predecessor.node = *(get_address_of_subtree(curr_node, key_location.key_idx));
	predecessor.key_idx = (curr_node -> num_keys) - 1;
	assert(predecessor.key < key_location.key);

	return predecessor;

}

KeyLocation get_in_order_successor(KeyLocation key_location) {
	// Return the key (with location) for key that would follow this one in an in-order traversal.
	assert(get_subtree(key_location.node, 0) != NULL);  // not a leaf
	KeyLocation successor;
	
	BTreeNode* curr_node = get_subtree(key_location.node, key_location.key_idx + 1);

	// Didn't use compound initializer for successor due to readability
	successor.key = query_min(curr_node);
	successor.node = *(get_address_of_subtree(curr_node, key_location.key_idx + 1));
	successor.key_idx = 0;
	assert(successor.key > key_location.key);

	return successor;
}

bool recursive_key_delete(BTreeNode** a_root, int key) {
	BTreeNode* root = *a_root;
	int key_idx = 0;

	while(key_idx < root -> num_keys && key > root -> keys[key_idx]) {
		key_idx++;
	}
	
	if(root -> keys[key_idx] == key && get_subtree(root, key_idx) != NULL) {
		KeyLocation key_location;
		key_location.node = root;
		key_location.key_idx = key_idx;
		key_location.key = root -> keys[key_location.key_idx];
		BTreeNode* left_child = get_subtree(root, key_idx);
		if(left_child -> num_keys >= MIN_KEYS + 1) {
			KeyLocation predecessor = get_in_order_predecessor(key_location);
			root -> keys[key_idx] = predecessor.key;
			(left_child -> num_keys)--;
			SUCCESS_DELETE = true;
		}
		else if(left_child -> num_keys < MIN_KEYS + 1) {
			BTreeNode* right_child = get_subtree(root, key_idx + 1);
			if(right_child -> num_keys >= MIN_KEYS + 1) {
				KeyLocation successor = get_in_order_successor(key_location);
				root -> keys[key_idx] = successor.key;
				for(int i = 0; i < (right_child -> num_keys) - 1; i++) {
					right_child -> keys[i] = right_child -> keys[i + 1];
				}
				(right_child -> num_keys)--;
				SUCCESS_DELETE = true;
			}	
			else if(right_child -> num_keys < MIN_KEYS + 1) {
				merge_subtree_with_next(root, key_idx);
				recursive_key_delete(&root, key);
			}
		}

	}	

	else if(root -> keys[key_idx] == key && get_subtree(root, key_idx) == NULL) {
		for(int i = key_idx; i < (root -> num_keys) - 1; i++) {
			root -> keys[i] = root -> keys[i + 1];
		}
		(root -> num_keys)--;
		SUCCESS_DELETE = true;
		assert(root -> num_keys >= MIN_KEYS);
	}

	else if(root -> keys[key_idx] != key && get_subtree(root, key_idx) == NULL) {
		SUCCESS_DELETE = false;
	}
	else {
		BTreeNode* new_root = get_subtree(root, key_idx);
		if(new_root -> num_keys == MIN_KEYS) {
			BTreeNode* right_child = get_subtree(root, key_idx + 1);
			if(key_idx == 0) {
				//BTreeNode* right_child = get_subtree(root, key_idx + 1);
				if(right_child -> num_keys >= MIN_KEYS + 1) {
					shift_key_backward(root, key_idx + 1);
				}
			}
			else {
				BTreeNode* left_child = get_subtree(root, key_idx - 1);
				if(left_child -> num_keys >= MIN_KEYS + 1) {
					shift_key_forward(root, key_idx - 1);
				}
				else if(right_child -> num_keys >= MIN_KEYS + 1) {
					shift_key_backward(root, key_idx + 1);
				}
			}
		}
		recursive_key_delete(&new_root, key);
	}
	
	return SUCCESS_DELETE;
}

bool delete_key(BTreeNode** a_root, int key) {
	if(*a_root == NULL) {
		return false;
	}
	bool delete = recursive_key_delete(a_root, key);

	return delete;
}
