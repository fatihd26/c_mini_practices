
#include "resistor.h"
#include <stdlib.h>

Resistor * createResistor(double resistance) {
    Resistor * resistor = malloc(sizeof(Resistor));
    resistor->node_wrapper_positive = createNodeWrapper();
    initNode(resistor->node_wrapper_positive);
    resistor->node_wrapper_negative = createNodeWrapper();
    initNode(resistor->node_wrapper_negative);
    resistor->resistance = resistance;
    return resistor;
}


void destroyResistor(Resistor * resistor) {
    freeNode(resistor->node_wrapper_positive);
    freeNode(resistor->node_wrapper_negative);
    free(resistor);
}

