
#include <stdio.h>
#include "src/matrix.h"
#include "src/components/circuit.h"

#include "src/components/node.h"
#include "src/components/resistor.h"
#include "src/solver/equal_resistance.h"

int main() {

    Circuit * circuit = createCircuit(8);

    Resistor * resistor1 = createResistor(100.0);
    Resistor * resistor2 = createResistor(200.0);
    Resistor * resistor3 = createResistor(300.0);
    Resistor * resistor4 = createResistor(400.0);

    addResistorToCircuit(resistor1, circuit);
    addResistorToCircuit(resistor2, circuit);
    addResistorToCircuit(resistor3, circuit);

    connectNodes(resistor2->node_wrapper_positive, resistor1->node_wrapper_negative);
    connectNodes(resistor1->node_wrapper_positive, resistor3->node_wrapper_negative);
    connectNodes(resistor3->node_wrapper_positive, resistor2->node_wrapper_negative);
    connectNodes(resistor3->node_wrapper_positive, resistor1->node_wrapper_negative);
    createGraphMatrix(circuit);

    fillMatrix(circuit);

    


    //solveEqualResistance(circuit);

    prettyMatrice(circuit->node_count, circuit->node_count, circuit->graph_matrix);

    //deleteResistorFromCircuit(circuit,resistor1);

    //prettyMatrice(circuit->node_count, circuit->node_count, circuit->graph_matrix);

    

    destroyResistor(resistor1);
    destroyResistor(resistor2);
    freeCircuit(circuit);
    freeMatrice(circuit->node_count, circuit->graph_matrix);
    




    


    


    return 0;
     
}


