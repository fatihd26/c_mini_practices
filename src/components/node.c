
#include "node.h"
#include <stdlib.h>

static int base_id = 0;

void initNode(NodeWrapper * node_wrapper){
    node_wrapper->node->connected_node_count = 1;
    node_wrapper->connecting_nodes = malloc(sizeof(Node*) * node_wrapper->node->connected_node_count);
}
NodeWrapper * createNodeWrapper(){
    NodeWrapper * node_wrapper = malloc(sizeof(NodeWrapper));
    node_wrapper->node = malloc(sizeof(Node));
    node_wrapper->node->id = base_id;
    base_id++;
    return node_wrapper;
}

void connectNodes(NodeWrapper * node1_wrapper, NodeWrapper * node2_wrapper){
    node1_wrapper->node->connected_node_count++;
    node2_wrapper->node->connected_node_count++;

    node1_wrapper->connecting_nodes = realloc(node1_wrapper->connecting_nodes, sizeof(Node*) * node1_wrapper->node->connected_node_count);
    node2_wrapper->connecting_nodes = realloc(node2_wrapper->connecting_nodes, sizeof(Node*) * node2_wrapper->node->connected_node_count);

    node1_wrapper->connecting_nodes[node1_wrapper->node->connected_node_count - 2] = *node2_wrapper->node;
    node2_wrapper->connecting_nodes[node2_wrapper->node->connected_node_count - 2] = *node1_wrapper->node;
}

int getBaseId(){
    return base_id;
}

void freeNode(NodeWrapper * node_wrapper){
    free(node_wrapper->connecting_nodes);
    free(node_wrapper->node);
    free(node_wrapper);
}