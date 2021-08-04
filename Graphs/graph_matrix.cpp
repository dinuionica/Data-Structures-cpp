#include "graph_matrix.hpp"

#define INF 999
int main(void) {

    // create graph
    GraphMatrix graph(4);

    // add new edges
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(0, 3);
    graph.AddEdge(0, 4);
    // print matrix
    graph.PrintMatrix();

    // dfs search
    graph.DfsSearch(4);
    std::cout << "\n";

    // bfs search
    graph.BfsSearch(4);
    std::cout << "\n";

    // check for bipartite graph
    graph.CheckBipartite();

    graph.FloydWarshall();
    return 0;
}