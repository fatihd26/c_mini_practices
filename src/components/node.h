#ifndef NODE_H
#define NODE_H


typedef struct
{
    int id;
    int connected_node_count;
}Node;

typedef struct{
    Node * node;
    Node * connecting_nodes;
}NodeWrapper;


void initNode(NodeWrapper * node_wrapper);

void freeNode(NodeWrapper * node_wrapper);

NodeWrapper * createNodeWrapper();

void connectNodes(NodeWrapper * node1_wrapper, NodeWrapper * node2_wrapper);

int getBaseId();


#endif
