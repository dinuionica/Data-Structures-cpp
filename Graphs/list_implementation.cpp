#include "list_implementation.hpp"

int main(void) {

    // create graph
    Graph graph(5);
    
    // add edges
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(1, 4);

    //remove edge
    graph.remove_edge(2,3);
    // print list

    graph.print_lists();

    // bsf search
    graph.bfs_search(1);

    //dfs search
    std::cout << "\n";
    graph.dfs_search();
    return 0;
}