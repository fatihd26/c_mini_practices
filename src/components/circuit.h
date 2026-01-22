
#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "node.h"
#include "resistor.h"
#include "../matrix.h"


typedef struct {
    
    int node_count;
    int capacity;
    int **graph_matrix;

    NodeWrapper * node_wrappers;

}Circuit;

void createGraphMatrix(Circuit * circuit);
Circuit * createCircuit(int initial_capacity);
void addNodeToCircuit(Circuit * circuit, NodeWrapper * node_wrapper);
void addResistorToCircuit(Resistor * resistor, Circuit * circuit);

void freeCircuit(Circuit * circuit);

void fillMatrix(Circuit * circuit);

void deleteNodeWrapperFromCircuit(Circuit * circuit, NodeWrapper * node_wrapper);
void deleteResistorFromCircuit(Circuit * circuit, Resistor * resistor);



#endif