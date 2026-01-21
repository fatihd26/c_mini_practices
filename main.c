
#include <stdio.h>
#include "src/matrix.h"
#include "src/components/circuit.h"

#include "src/components/node.h"
#include "src/components/resistor.h"

int main() {

    Circuit * circuit = createCircuit(4);

    Resistor * resistor1 = createResistor(100.0);
    Resistor * resistor2 = createResistor(200.0);

    addResistorToCircuit(resistor1, circuit);
    addResistorToCircuit(resistor2, circuit);



    connectNodes(resistor1->node_wrapper_positive, resistor2->node_wrapper_positive);
    connectNodes(resistor1->node_wrapper_negative, resistor2->node_wrapper_negative);
    createGraphMatrix(circuit);

    fillMatrix(circuit);


    prettyMatrice(circuit->node_count, circuit->node_count, circuit->graph_matrix);

    deleteResistorFromCircuit(circuit,resistor1);

    prettyMatrice(circuit->node_count, circuit->node_count, circuit->graph_matrix);

    

    
    freeCircuit(circuit);
    freeMatrice(circuit->node_count, circuit->graph_matrix);
    




    


    


    return 0;
     
}


