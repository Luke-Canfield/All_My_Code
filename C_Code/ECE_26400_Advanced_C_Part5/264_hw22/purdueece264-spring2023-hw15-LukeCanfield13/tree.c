// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

TreeNode* build_helper(int * inArray, int * postArray, int size) {
	if(size == 0) {
		return NULL;
	}
	int root = postArray[size - 1]; //root is last value of postArray
	int i = 0;

	// iterate until root is found within inArray
	while(inArray[i] != root) {
		i++;
	}

	TreeNode* new_node = malloc(sizeof(TreeNode)); //make new node
	new_node->value = root;                        //assign node value to root
	new_node->left = build_helper(inArray, postArray, i); //build left tree with recursion
	new_node->right = build_helper(&inArray[i + 1], &postArray[i], size - 1 - i); //build right tree with recursion
	return new_node;
}

Tree * buildTree(int * inArray, int * postArray, int size) {
	Tree *new_tree = malloc(sizeof(Tree));
	new_tree->root = build_helper(inArray, postArray, size);
	return new_tree;
}
#endif
