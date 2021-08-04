#ifndef __MATRIX_IMPLEMENTATION__
#define __MATRIX_IMPLEMENTATION__

#include <iostream>
#include <string>

// class of a graph implemented with adiacent matrix
class Graph {
private:
    int num_vertices;
    int **matrix;

public:
    // constructor 
    Graph(int num_vertices) {
        this->num_vertices = num_vertices;
        matrix = new int*[num_vertices];
        for (int i = 0; i < num_vertices; ++i) {
            matrix[i] = new int[num_vertices];
        for (int j = 0; j < num_vertices; ++j) 
            matrix[i][j] = 0;
        }
    }

    // function to add a new edge between source and destination
    void add_edge(int src, int dest) {
        matrix[src][dest] = 1;
        matrix[dest][src] = 1;
    }
    
    // function to remove an the edge between source and destination
    void remove_edge(int src, int dest) {
        matrix[src][dest] = 0;
        matrix[dest][src] = 0;
    }

    // function to print vertices
    void print_vertices() {
        for (int i = 0; i < num_vertices; ++i) {
            std::cout << i << " : ";
            for (int j = 0; j < num_vertices; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

#endif // __MATRIX_IMPLEMENTATION__