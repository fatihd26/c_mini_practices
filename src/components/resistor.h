#ifndef RESISTOR_H
#define RESISTOR_H
#include "node.h"

typedef struct{
    double resistance;
    NodeWrapper * node_wrapper_positive;
    NodeWrapper * node_wrapper_negative;
} Resistor;

Resistor * createResistor(double resistance);

void destroyResistor(Resistor * resistor);

static int resistor_id;
static Resistor ** resistors;
int getResistorId();
Resistor * getResistor(int index);

#endif
