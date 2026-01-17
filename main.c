
#include <stdio.h>
#include "src/matrix.h"
#include "src/components/circuit.h"

#include "src/components/node.h"

int main() {

    Circuit * circuit = createCircuit(2);

    NodeWrapper * node_wrapper1 = createNodeWrapper();
    initNode(node_wrapper1);

    addNodeToCircuit(circuit, node_wrapper1);

    NodeWrapper * node_wrapper2 = createNodeWrapper();
    initNode(node_wrapper2);

    addNodeToCircuit(circuit, node_wrapper2);

    createGraphMatrix(circuit);

    for (int i = 0; i < circuit->node_count; i++) {
            if (circuit->node_wrappers[i].node->connected_node_count >= 1){
                for (int j = 0; j< circuit->node_wrappers[i].connecting_nodes[j].connected_node_count; j++) {
                    setMatriceValue(circuit->graph_matrix,circuit->node_wrappers[i].node->connected_node_count, circuit->node_wrappers[i].connecting_nodes[j].id, 1);
                }
            }
    }

    prettyMatrice(circuit->node_count, circuit->node_count, circuit->graph_matrix);


    freeCircuit(circuit);
    freeMatrice(circuit->node_count, circuit->graph_matrix);
    

    freeNode(node_wrapper1);
    freeNode(node_wrapper2);



    


    


    return 0;
     
}


