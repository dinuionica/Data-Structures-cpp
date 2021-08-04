#include "matrix_implementation.hpp"

int main(void) {

    Graph graph(10);
    graph.add_edge(1,2);
    graph.add_edge(2,3);
    graph.add_edge(3,4);

   graph.print_vertices();

    return 0;
}