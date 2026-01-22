
#include "resistor.h"
#include <stdlib.h>

static int resistor_id = 0;
static Resistor ** resistors = NULL;

void initResistor(Resistor * resistor) {
    

    if (resistor_id == 0)
    {   

        resistors = malloc(sizeof *resistors);
        resistors[resistor_id] = resistor;
        resistor_id++;
    }
    else
    {   
        
        resistors = realloc(resistors, sizeof *resistors * (resistor_id + 1));
        resistors[resistor_id] = resistor;
        resistor_id++;
    }


    
    

}

Resistor * createResistor(double resistance) {
    Resistor * resistor = malloc(sizeof(Resistor));
    resistor->node_wrapper_positive = createNodeWrapper();
    initNode(resistor->node_wrapper_positive);
    resistor->node_wrapper_negative = createNodeWrapper();
    initNode(resistor->node_wrapper_negative);
    resistor->resistance = resistance;
    initResistor(resistor);
    return resistor;
}


void destroyResistor(Resistor * resistor) {
    freeNode(resistor->node_wrapper_positive);
    freeNode(resistor->node_wrapper_negative);
    free(resistor);
}


int getResistorId(){
    return resistor_id;
}

Resistor * getResistor(int index){
    return resistors[index];
}





