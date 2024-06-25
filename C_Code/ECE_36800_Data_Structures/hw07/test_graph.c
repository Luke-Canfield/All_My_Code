#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <time.h>  // enables srand(time(NULL)) to make pseudorandom generator better
#include "graph.h"

Graph create_non_random_wheel_graph() {
	Graph wheel_graph = create_graph_with_no_edges(5);
	wheel_graph.weights_from_to[0][1] = 2;
	wheel_graph.weights_from_to[1][0] = 2;
	wheel_graph.weights_from_to[0][2] = 2;
	wheel_graph.weights_from_to[2][0] = 2;
	wheel_graph.weights_from_to[0][3] = 2;
	wheel_graph.weights_from_to[3][0] = 2;
	wheel_graph.weights_from_to[0][4] = 2;
	wheel_graph.weights_from_to[4][0] = 2;
	wheel_graph.weights_from_to[1][2] = 2;
	wheel_graph.weights_from_to[2][3] = 2;
	wheel_graph.weights_from_to[3][4] = 2;
	wheel_graph.weights_from_to[4][1] = 2;
	return wheel_graph;
}

Graph create_non_random_cycle_graph() {
	Graph cycle_graph = create_graph_with_no_edges(4);
	cycle_graph.weights_from_to[0][1] = 2;
	cycle_graph.weights_from_to[1][2] = 2;
	cycle_graph.weights_from_to[2][3] = 2;
	cycle_graph.weights_from_to[3][0] = 2;
	return cycle_graph;
}

void demo() {
	// These are not random graphs.  This is just to illustrate what some of the graph types
	// will look like when it works.
	Graph wheel_graph = create_non_random_wheel_graph();
	//print_graph("Wheel (not random)", wheel_graph);

	//Test for get_in_degree & get_out_degree
	int edges_to_idx = get_in_degree(wheel_graph, 0);
	int edges_from_idx = get_out_degree(wheel_graph, 3);
	printf("edges to index 0: %d\n", edges_to_idx);
	printf("edges from index 3: %d\n", edges_from_idx);
	//assert(is_strongly_connected(wheel_graph));
	free_graph(&wheel_graph);
	
	//Test for create_random_complete_graph
	size_t num_vertices = 5;
	Graph rand_complete_graph = create_random_complete_graph(num_vertices);
	print_graph("random_complete_graph", rand_complete_graph);
	free_graph(&rand_complete_graph);

	//Test for create_random_cycle_graph
	size_t num_vertices_2 = 4;
	Graph rand_cycle_graph = create_random_cycle_graph(num_vertices_2);
	bool connected = is_strongly_connected(rand_cycle_graph);
	print_graph("random_cycle_graph", rand_cycle_graph);
	if(connected == 1) {
		printf("rand_cycle_graph is strongly connected\n");
	}
	else {
		printf("Error in is_strongly_connected function");
	}
	free_graph(&rand_cycle_graph);

	//Test for create_random_wheel_graph
	size_t num_vertices_3 = 6;
	Graph rand_wheel_graph = create_random_wheel_graph(num_vertices_3);
	print_graph("random_wheel_graph", rand_wheel_graph);
	free_graph(&rand_wheel_graph);

	//Test for create_random_graph
	size_t num_vertices_4 = 4;
	size_t num_edges = 7;
	Graph rand_graph = create_random_graph(num_vertices_4, num_edges);
	bool connected_1 = is_strongly_connected(rand_graph);
	print_graph("random_graph", rand_graph);
	if(connected_1 == 1) {
		printf("random_graph is strongly connected\n");
	}
	if(connected_1 == 0) {
		printf("random_graph is not strongly connected\n");
	}
	free_graph(&rand_graph);

	//Graph cycle_graph = create_non_random_cycle_graph();
	//print_graph("Cycle (not random)", cycle_graph);
	//assert(is_strongly_connected(cycle_graph));
	//free_graph(&cycle_graph);
	/*
	After completing the get_in_degree(…) and get_out_degree(…), output should look like this:
	--
	Wheel (not random)
	∙ A (in=4/out=4): →B (2), →C (2), →D (2), →E (2)
	∙ B (in=2/out=2): →A (2), →C (2)
	∙ C (in=2/out=2): →A (2), →D (2)
	∙ D (in=2/out=2): →A (2), →E (2)
	∙ E (in=2/out=2): →A (2), →B (2)

	Cycle (not random)
	∙ A (in=1/out=1): →B (2)
	∙ B (in=1/out=1): →C (2)
	∙ C (in=1/out=1): →D (2)
	∙ D (in=1/out=1): →A (2)
	*/

}

int main(int argc, char* argv[]) {
	srand(time(NULL));

	demo();

	return EXIT_SUCCESS;
}
#define VERSION_TEST_GRAPH_C 1*
