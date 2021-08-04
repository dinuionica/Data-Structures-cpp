#ifndef _GRAPH_MATRIX_HPP
#define _GRAPH_MATRIX_HPP

#include <iostream>
#include <queue>
#include <map>

#define INF 999

// class of a Graph implemented using a matrix
class GraphMatrix {

private:
    int **matrix;
    int size;

public:
    // constructor 
    GraphMatrix(int size) {
        this->size = size;
        matrix = new int*[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = new int[size];
        for (int j = 0; j < size; ++j) 
            matrix[i][j] = 0;
        }
    }
    
    // the function that add a new edge
    void AddEdge(int src, int dest) {
        matrix[src][dest] = 1;
    }

    // the function that remove a new edge
    void RemoveEdge(int src, int dest) {
        matrix[src][dest] = 0;
    }

    // the function that print matrix of graph
    void PrintMatrix() {
        for (int i = 0; i < size; ++i) {
            std::cout << i << "->";
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j] == 1) {
                    std::cout << " " << j << " ";
                }
            }
            std::cout << "\n";
        }
    }

    // destructor
    ~GraphMatrix() {
        for (int i = 0; i < size; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // bfs search implementation
    void BfsSearch(int source) {

        std::queue<int> queue;
        // declare the visited vector
        bool visited[size];
        for (int i = 0; i < size; ++i) {
            visited[i] = false;
        }
        // set current node as visited
        visited[source] = true;
        queue.push(source);

        while (!queue.empty()) {
            // acces the top of the queue, pop and then print
            int top = queue.front();
            queue.pop();
            std::cout << top << " ";
            // find all unvisited neighbors
            for (int j = 0; j < size; ++j) {
                if (matrix[top][j] == 1 && visited[j] == false) {
                   visited[j] = true;
                   queue.push(j);
                }
            }
        }
    }

    // dfs search implementation
    void __Dfs(int start, bool *visited) {
        // print source
        std::cout << start << " ";
        // set current node as visited
        visited[start] = true;
        // find all unvisited neighbors
        for (int i = 0; i < size; i++) {
            if (matrix[start][i] == 1 && (!visited[i])) {
                __Dfs(i, visited);
            }
        }
    } 

    void DfsSearch(int source) {
        // create and initialize the visited vector
        bool visited[size];
        for (int i = 0; i < size; ++i) {
            visited[i] = false;
        }
        __Dfs(source, visited);
    } 

    bool __CheckBipartite(int source, int *level) {
        
        std::queue<int> queue;
      
        // put source on odd nivel
        level[source] = 0;
        queue.push(source);

        while (!queue.empty()) {
            int top = queue.front();
            queue.pop();


            for (int j = 0; j < size; ++j) {
                // if level of j is undefind
                if (level[j] == -1 && matrix[top][j] == 1) {
                    // if level[top] is odd
                    if (level[top] == 0) {
                        // level[j] is even
                        level[j] = 1;
                    }
                    // if level[top] is even
                    else if (level[top] == 1) {
                        // level[j] is oden
                        level[j] = 0;
                    }
                    queue.push(j);
                }
                // if they have the same level
                else if (level[j] == level[top] && matrix[top][j] == 1) {
                    return false;
                }
            }
        }
        return true;
    }
    // the function that check if a graph is bipartite 
    void CheckBipartite() {
        bool response = true;
        int level[size];
        for (int i = 0; i < size; ++i) {
            level[i] = -1;
        }
        for (int j = 0; j < size; ++j) {
            if (level[j] == -1) {
                response = __CheckBipartite(j, level);
                if (response == false) {
                    break;
                }
            }
        }
        if (response == false) {
            std::cout << "False" << "\n";
        } else {
            std::cout << "True" << "\n";
        }
    }
    
    // Floyd Warshall algorithm
    void FloydWarshall() {

        // declare a matrix of costs
        int matrix[4][4] = {{ 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 }};    

        // declare the distance matrix
        int distance[size][size];

        // copy all cost element in new matrix
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                distance[i][j] = matrix[i][j];
            }
        }

        // calculate min cost
        for (int k = 0; k < size; ++k) {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (distance[i][j] > distance[i][k] + distance[k][j] 
                        && distance[i][k] != INF && distance[k][j] != INF) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
        // print matrix
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << distance[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

#endif // _GRAPH_MATRIX_HPP
