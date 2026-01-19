
#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "node.h"

typedef struct {
    NodeWrapper * node_wrappers;
    int node_count;
    int capacity;
    int **graph_matrix;

}Circuit;

void createGraphMatrix(Circuit * circuit);
Circuit * createCircuit(int initial_capacity);
void addNodeToCircuit(Circuit * circuit, NodeWrapper * node_wrapper);
void freeCircuit(Circuit * circuit);

void fillMatrix(Circuit * circuit);

#endif