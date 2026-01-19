
#include <stdio.h>
#include "src/matrix.h"
#include "src/components/circuit.h"

#include "src/components/node.h"

int main() {

    Circuit * circuit = createCircuit(4);

    NodeWrapper * node_wrapper1 = createNodeWrapper();
    initNode(node_wrapper1);
    addNodeToCircuit(circuit, node_wrapper1);

    NodeWrapper * node_wrapper2 = createNodeWrapper();
    initNode(node_wrapper2);
    addNodeToCircuit(circuit, node_wrapper2);

    NodeWrapper * node_wrapper3 = createNodeWrapper();
    initNode(node_wrapper3);
    addNodeToCircuit(circuit, node_wrapper3);

    NodeWrapper * node_wrapper4 = createNodeWrapper();
    initNode(node_wrapper4);
    addNodeToCircuit(circuit, node_wrapper4);

    
    connectNodes(node_wrapper1, node_wrapper2);
    connectNodes(node_wrapper3, node_wrapper4);

    printf("%d\n", circuit->node_count);
    createGraphMatrix(circuit);

    fillMatrix(circuit);


    prettyMatrice(circuit->node_count, circuit->node_count, circuit->graph_matrix);


    freeCircuit(circuit);
    freeMatrice(circuit->node_count, circuit->graph_matrix);
    

    freeNode(node_wrapper1);
    freeNode(node_wrapper2);



    


    


    return 0;
     
}


