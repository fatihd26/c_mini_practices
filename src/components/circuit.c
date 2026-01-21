
#include "circuit.h"

Circuit * createCircuit(int initial_capacity){
    Circuit * circuit = malloc(sizeof(Circuit));
    circuit->node_wrappers = malloc(sizeof(NodeWrapper) * initial_capacity);
    circuit->node_count = 0;
    circuit->capacity = initial_capacity;
    return circuit;
}

void addNodeToCircuit(Circuit *circuit, NodeWrapper *node_wrapper) {
    if (circuit->node_count+1 > circuit->capacity) {
        circuit->capacity = circuit->capacity * 2;
        NodeWrapper * temp = realloc(circuit->node_wrappers, sizeof(NodeWrapper) * (circuit->capacity));
        if (!temp){ 
            return;
        }
        

        else{
            circuit->node_wrappers = temp;
        }
    }
    
    circuit->node_wrappers[circuit->node_count] = *node_wrapper;
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

void fillMatrix(Circuit * circuit){
    for (int i = 0; i < circuit->node_count; i++) {

      for (int j = 0; j < circuit->node_wrappers[i].node->connected_node_count-1; j++) {
            int id_base = circuit->node_wrappers[i].node->id;
            int id_connected = circuit->node_wrappers[i].connecting_nodes[j].id;

            setMatriceValue(circuit->graph_matrix, id_base,id_connected, 1);
            setMatriceValue(circuit->graph_matrix, id_base, id_base, 0);
            setMatriceValue(circuit->graph_matrix, id_connected, id_connected, 0);

            

        }
    }
}





void deleteNodeWrapperFromCircuit(Circuit * circuit, NodeWrapper * node_wrapper){
    int index = -1;
    for (int i = 0; i < circuit->node_count; i++) {
        if (circuit->node_wrappers[i].node->id == node_wrapper->node->id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return;
    }

    for (int i = index; i < circuit->node_count - 1; i++) {
        circuit->node_wrappers[i] = circuit->node_wrappers[i + 1];
    }
    circuit->node_count--;


    fillMatrix(circuit);
}


void addResistorToCircuit(Resistor * resistor, Circuit * circuit) {
    addNodeToCircuit(circuit, resistor->node_wrapper_positive);
    addNodeToCircuit(circuit, resistor->node_wrapper_negative);
}

void deleteResistorFromCircuit(Circuit * circuit, Resistor * resistor) {
    deleteNodeWrapperFromCircuit(circuit, resistor->node_wrapper_positive);
    deleteNodeWrapperFromCircuit(circuit, resistor->node_wrapper_negative);
    destroyResistor(resistor);
}