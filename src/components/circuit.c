
#include "circuit.h"
#include "../matrix.h"

Circuit * createCircuit(int initial_capacity){
    Circuit * circuit = malloc(sizeof(Circuit));
    circuit->node_wrappers = malloc(sizeof(NodeWrapper) * initial_capacity);
    circuit->node_count = 0;
    circuit->capacity = initial_capacity;
    return circuit;
}

void addNodeToCircuit(Circuit *circuit, NodeWrapper *node_wrapper) {
    if (circuit->node_count >= circuit->capacity) {
        circuit->capacity *= 2;
        NodeWrapper *temp = realloc(circuit->node_wrappers, sizeof(NodeWrapper) * circuit->capacity);
        if (!temp) return; // realloc başarısız, hata yönetimi
        circuit->node_wrappers = temp;
    }

    // Heap pointer paylaşımı yerine pointer’ı tutmak daha güvenli
    circuit->node_wrappers[getBaseId()-1] = *node_wrapper;
    circuit->node_count++;
}


void freeCircuit(Circuit * circuit){
    free(circuit->node_wrappers);
    circuit->node_wrappers = NULL;
    circuit->node_count = 0;
    circuit->capacity = 0;
    free(circuit);
}

void createGraphMatrix(Circuit * circuit){
    circuit->graph_matrix = createMatrice(circuit->node_count, circuit->node_count);
}