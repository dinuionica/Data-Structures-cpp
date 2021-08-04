#include "graph_list.hpp"

int main(void) {

    GraphList g(5);
    g.AddEdge(1, 0);
    g.AddEdge(0, 2);
    g.AddEdge(2, 1);
    g.AddEdge(0, 3);
    g.AddEdge(3, 4);

    g.PrintNumberComponoent();
    return 0;
}