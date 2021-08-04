#ifndef __GRAPH_LIST_HPP_
#define __GRAPH_LIST_HPP_

#include <iostream>
#include <list>
#include <queue>
#include <stack>


class GraphList {

private:
    std::list<int> *adj;
    int number_vertices;

public:

    // constructor
    GraphList(int vertices) {
        this->number_vertices = vertices;
        this->adj = new std::list<int> [vertices];
    }  

    // the function that add an edge
    void AddEdge(int src, int dest) {
        adj[src].push_back(dest);
    }

    // the function that remove an edge
    void RemoveEdge(int src, int dest) {
        std::list<int>::iterator it;
        it = adj[src].begin();
        while (it != adj[src].end()) {

            if (*it == dest) {
                adj[src].erase(it);
                break;
            }
            it++;
        }
    }

    // the function that print lists
    void PrintList() {
        for (int i = 0; i < number_vertices; ++i) {
            std::cout << i << "->";
            for (auto it:adj[i]) {
                std::cout << it << " ";
            }
            std::cout << "\n";
        }
    }

    // bfs algorithm implementation
    void BfsSearch(int source) {
        std::queue<int> queue;
        bool visited[number_vertices];

        for (int i = 0; i < number_vertices; ++i) {
            visited[i] = false;
        }

        visited[source] = true;
        queue.push(source);

        while (!queue.empty()) {
            int front = queue.front();
            queue.pop();
            std::cout << front << " ";
            for (auto it = adj[front].begin(); it != adj[front].end(); ++it) {
                if (visited[*it] == false) {
                    visited[*it] = true;
                    queue.push(*it);
                }
            }
        }
    }

    // dfs algorithm implementation
    void __DfsSearch(int source, bool *visited) {
        
        visited[source] = true;
        std::cout << source << " ";
        for (auto it = adj[source].begin(); it != adj[source].end(); ++it) {
            if (visited[*it] == false) {
                __DfsSearch(*it, visited);
            }
        }
    }
    void DfsSearch(int source) {
        bool visited[number_vertices];
        for (int i = 0; i < number_vertices; ++i) {
            visited[i] = false;
        }
        __DfsSearch(source,visited);
    }

    // the function that transpose a graph
    GraphList Transpose() {
        GraphList new_graph(number_vertices);
        for (int i = 0; i < number_vertices; ++i) {
            for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
                new_graph.adj[*it].push_back(i);       
            }
        }
        return new_graph;
    }

    // the function that fill elements in stack
    void FillOrder(int source, bool *visited, std::stack<int> &stack) {

       visited[source] = true;
       for (auto it = adj[source].begin(); it != adj[source].end(); ++it) {
           if (!visited[*it]) {
               FillOrder(*it, visited, stack);
           }
       }
       stack.push(source); 
    }
    
    // the function that print number of hard conex component
    void PrintNumberComponoent() {
        std::stack<int> stack;
        bool visited[number_vertices];

        for (int i = 0; i < number_vertices; ++i) {
            visited[i] = false;
        }

        // first dfs
        for (int i = 0; i < number_vertices; ++i) {
            if (!visited[i]) {
                FillOrder(i, visited, stack);
            }
        }

        GraphList gr = Transpose();

        for (int i = 0; i < number_vertices; ++i) {
            visited[i] = false;
        }
        
        // second dfs
        while (!stack.empty()) {
            int top = stack.top();
            stack.pop();
            if (visited[top] == false) {
                gr.__DfsSearch(top,visited);
                std::cout << "\n";
            }
        }
    }
};


#endif // __GRAPH_LIST_HPP_