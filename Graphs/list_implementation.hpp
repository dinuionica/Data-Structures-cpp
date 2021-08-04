#ifndef __LIST_IMPLEMENTATION__
#define __LIST_IMPLEMENTATION__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>


using namespace std;
class Graph {

private:
    int num_vertices;
    std::list<int> *adj;

public:
    // constructor

    Graph(int vertices) {
        this->num_vertices = vertices;
        adj = new std::list<int>[vertices];
    }

    // function to add a new edge between src and dest
    void add_edge(int src, int dest) {
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    // functions to remove the edge between src and dest
    void __remove_edge(int src, int dest) {
   
        std::list<int>::iterator it  = adj[src].begin();
        for (; it != adj[src].end(); ++it) {
            if (*it == dest) {
                adj[src].erase(it);
                break;
            }
        }
    }

    void remove_edge(int src, int dest) {
        __remove_edge(src, dest);
        __remove_edge(dest, src);
    }

    // function to print the list of vertices
    void print_lists() {
        for (int i = 0; i < num_vertices; ++i) {
            std::cout << i << " --> ";
            for (auto it:adj[i]) {
                std::cout << it << " ";
            }
            std::cout << "\n";
        }
    }

    // function for bsf search algortihm
    void bfs_search(int source) {

        std::queue<int> queue_nodes;
        bool visited[num_vertices];

        for (int i = 0; i < num_vertices; ++i) {
            visited[i] = false;
        }

        visited[source] = true;
        queue_nodes.push(source);

        while (!queue_nodes.empty()) {
            int front = queue_nodes.front();
            std::cout << front << " ";
            queue_nodes.pop();
            for (auto it = adj[front].begin(); it != adj[front].end(); ++it) {
                if (visited[*it] == false) {
                    visited[*it] = true;
                    queue_nodes.push(*it);
                }
            }
        }
    }

    // functions for dfs search algorithm?
    void __dfs_search(int source, bool *visited) {
        visited[source] = true;
        std::cout << source << " ";

        for (auto it = adj[source].begin(); it != adj[source].end(); ++it) {
            if (!visited[*it]) {
                __dfs_search(*it, visited);
            }
        }
    }

    void dfs_search() {
        bool visited[num_vertices];
        for (int i = 0; i < num_vertices; ++i) {
            visited[i] = false;
        }

        for (int i = 0; i < num_vertices; ++i) {
            if (visited[i] == false) {
                __dfs_search(i, visited);
            }
        }
    }
};

#endif // __LIST_IMPLEMENTATION__
