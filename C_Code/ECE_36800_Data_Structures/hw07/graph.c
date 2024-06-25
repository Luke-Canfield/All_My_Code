#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <time.h>  // enables srand(time(NULL)) to make pseudorandom generator better
#include "graph.h"

// HELPER FUNCTIONS
int _get_random_weight();
void _shuffle_idxs(size_t* idxs, size_t num_idxs);
size_t* _get_shuffled_idxs(size_t num_idxs);

int get_in_degree(Graph graph, int idx_of_vertex_to) {
	int edges_to_vertex = 0;
	if(idx_of_vertex_to < graph.num_vertices) {
		for(size_t i = 0; i < graph.num_vertices; i++) {
			if(graph.weights_from_to[i][idx_of_vertex_to] != 0) {
				edges_to_vertex++;
			}
		}
	}
	else {
		printf("Invalid vertex idx\n");
	}

	return edges_to_vertex;
}

int get_out_degree(Graph graph, int idx_of_vertex_from) {
	int edges_from_vertex = 0;
	if(idx_of_vertex_from < graph.num_vertices) {
		for(size_t i = 0; i < graph.num_vertices; i++) {
			if(graph.weights_from_to[idx_of_vertex_from][i] != 0) {
				edges_from_vertex++;
			}
		}
	}
	else {
		printf("Invalid vertex idx\n");
	}

	return edges_from_vertex;
}

Graph create_random_complete_graph(size_t num_vertices) {
	Graph rand_complete_graph = create_graph_with_no_edges(num_vertices);

	for(size_t i = 0; i < num_vertices; i++) {
		for(size_t j = 0; j < num_vertices; j++) {
			if(i != j) {
				rand_complete_graph.weights_from_to[i][j] = _get_random_weight();
			}
		}
	}

	return rand_complete_graph;
}

Graph create_random_cycle_graph(size_t num_vertices) {
	assert(num_vertices >= 2);
	Graph rand_cycle_graph = create_graph_with_no_edges(num_vertices);
	
	size_t* shuffled_idxs = _get_shuffled_idxs(num_vertices);

	for(size_t i = 0; i < num_vertices; i++) {
		size_t from_idx = shuffled_idxs[i];
		size_t to_idx = 0;
		if(i == num_vertices - 1) {
			to_idx = shuffled_idxs[0];
		}
		else {
			to_idx = shuffled_idxs[i + 1];
		}
		rand_cycle_graph.weights_from_to[from_idx][to_idx] = _get_random_weight();
	}

	free(shuffled_idxs);

	return rand_cycle_graph;

}

Graph create_random_wheel_graph(size_t num_vertices) {
	assert(num_vertices >= 3);
	Graph rand_wheel_graph = create_graph_with_no_edges(num_vertices);

	size_t* shuffled_idxs = _get_shuffled_idxs(num_vertices);
	for(size_t i = 0; i < num_vertices; i++) {
		if(shuffled_idxs[0] != i) {
			rand_wheel_graph.weights_from_to[shuffled_idxs[0]][i] = _get_random_weight();
			rand_wheel_graph.weights_from_to[i][shuffled_idxs[0]] = _get_random_weight();
		}
	}
	
	for(size_t i = 0; i < num_vertices; i++) {
		if(shuffled_idxs[i] != shuffled_idxs[0]) {
			if(i == num_vertices - 1) {
				rand_wheel_graph.weights_from_to[shuffled_idxs[i]][shuffled_idxs[1]] = _get_random_weight();
			}
			else {
				rand_wheel_graph.weights_from_to[shuffled_idxs[i]][shuffled_idxs[i + 1]] = _get_random_weight();
			}
		}
	}

	free(shuffled_idxs);

	return rand_wheel_graph;
}

Graph create_random_graph(size_t num_vertices, size_t num_edges) {
	Graph rand_graph =  create_graph_with_no_edges(num_vertices); 

	size_t* shuffled_idxs = _get_shuffled_idxs(num_vertices);
	size_t curr_edges = 0;
	
	while(curr_edges < num_edges) {
		size_t rand_from_idx = rand() % num_vertices;
		size_t rand_to_idx = rand() % num_vertices;
		if(rand_graph.weights_from_to[shuffled_idxs[rand_from_idx]][shuffled_idxs[rand_to_idx]] == 0) {
			rand_graph.weights_from_to[shuffled_idxs[rand_from_idx]][shuffled_idxs[rand_to_idx]] = _get_random_weight();
			curr_edges++;
		}
	}

	free(shuffled_idxs);

	return rand_graph;
}

void _dfs_helper(Graph graph, bool* visited, size_t start_idx) {
	visited[start_idx] = true;
	for(size_t i = 0; i < graph.num_vertices; i++) {
		if(graph.weights_from_to[start_idx][i] != 0 && !visited[i]) {
			_dfs_helper(graph, visited, i);
		}
	}
}

bool is_strongly_connected(Graph graph) {  
	bool* visited = (bool*) malloc(graph.num_vertices * sizeof(bool));

	for(size_t start_idx = 0; start_idx < graph.num_vertices; start_idx++) {
		for(size_t i = 0; i < graph.num_vertices; i++) {
			visited[i] = false;
		}
		_dfs_helper(graph, visited, start_idx);
		for(size_t i = 0; i < graph.num_vertices; i++) {
			if(!visited[i]) {
				free(visited);
				return false;
			}
		}
	}

	free(visited); 

	return true;  
}

Graph create_graph_with_no_edges(size_t num_vertices) {
	// Create a graph containing vertices but no edges.  Note:  weight of 0 indicates no edge.
	Graph graph = {
		.num_vertices = num_vertices,
		.weights_from_to = malloc((sizeof *graph.weights_from_to) * num_vertices
								+ (sizeof **graph.weights_from_to) * num_vertices * num_vertices) };
	int* a_weight_0_to_0 = (int*)(&graph.weights_from_to[num_vertices]);
	for(size_t idx_of_vertex_from = 0; idx_of_vertex_from < num_vertices; idx_of_vertex_from++) {
		graph.weights_from_to[idx_of_vertex_from] = a_weight_0_to_0 + idx_of_vertex_from * num_vertices;
		for(int vertex_idx_to = 0; vertex_idx_to < num_vertices; vertex_idx_to++) {
			graph.weights_from_to[idx_of_vertex_from][vertex_idx_to] = 0;
		}
	}
	/* This "matrix" is stored as an array of arrays.  First, there is an array of addresses to
	 * each array (row).  Then, there are 'num_vertices' arrays (one for each row of the matrix).
	 * To reduce calls to malloc(..) and simplify freeing, we combine all of that into one block.
	 *
	 * You can simply refer to it the same as you would a 2D array.
	 * Ex: graph.weights_from_to[2][3] = 5;
	 *     // creates an edge from vertex 2 to vertex 3 with weight 5.
	 */
	return graph;
}

void print_graph(char const* label, Graph graph) {
	// Print the graph as text. including the in-degree and out-degree.
	// ∙ Okay to modify this to your liking, if you wish.
	char* labels[] = { "A","B","C","D","E","F","G","H","I","J","K","L","M",
		                "N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
	size_t num_labels = sizeof labels / sizeof labels[0];
	assert(graph.num_vertices < num_labels);  // add more labels above, if you want to do larger graphs

	printf("%s\n", label);
	for(size_t idx_vertex = 0; idx_vertex < graph.num_vertices; idx_vertex++) {
		printf("∙ %s ", labels[idx_vertex]);
		int in_degree = get_in_degree(graph, idx_vertex);
		int out_degree = get_out_degree(graph, idx_vertex);
		printf("(in=%d/out=%d): ", in_degree, out_degree);
		bool found_edge = false;
		for(size_t vertex_idx_to = 0; vertex_idx_to < graph.num_vertices; vertex_idx_to++) {
			//if(idx_vertex != vertex_idx_to) {
			int weight = graph.weights_from_to[idx_vertex][vertex_idx_to];
			if(weight >= 1) {
				if(found_edge) {
					printf(", ");
				}
				else {
					found_edge = true;
				}
				printf("→%s (%d)", labels[vertex_idx_to], weight);
			}
		}
		//}
		if(!found_edge) {
			printf("(no edges)");
		}
		printf("\n");
	}
	printf("\n");
}

void free_graph(Graph* a_graph) {
	// Free the matrix (array of arrays) the 'Graph' object refers to.
	free(a_graph -> weights_from_to);
	a_graph -> weights_from_to = NULL;
	a_graph -> num_vertices = 0;
}

int _get_random_weight() {
	// Return a random int from 1 to MAX_WEIGHT, inclusive.
	int MAX_WEIGHT = 5;
	int random_weight = rand() % MAX_WEIGHT + 1;
	assert(random_weight >= 0 && random_weight <= MAX_WEIGHT);
	return random_weight;
}

size_t* _get_shuffled_idxs(size_t num_idxs) {
	// Return an array of indexes (numbers) from 0 to (num_idxs - 1), in random order.
	// ∙ Caller is responsible for freeing memory.
	// ∙ You can call _shuffle_idxs(…) to shuffle the array again in-place without recreating it.
	size_t* idxs = malloc(num_idxs * sizeof *idxs);
	for(size_t i = 0; i < num_idxs; i++) {
		idxs[i] = i;
	}
	_shuffle_idxs(idxs, num_idxs);
	//for(int i = 0; i < num_idxs; i++) {
	//	printf("%zd%s", idxs[i], i + 1 < num_idxs ? ", " : "\n");
	//}
	return idxs;
}

void _shuffle_idxs(size_t* idxs, size_t num_idxs) {
	// Re-shuffle an array of indexes created with _get_shuffled_idxs(…).
	for(size_t src_pos = num_idxs - 1; src_pos >= 1; src_pos--) {
		size_t dst_pos = rand() % src_pos;
		size_t copy_of_dst = idxs[dst_pos];
		idxs[dst_pos] = idxs[src_pos];
		idxs[src_pos] = copy_of_dst;
	}
}

#define VERSION_GRAPH_C 1
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
