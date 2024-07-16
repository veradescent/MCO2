#ifndef GRAPH_H
#define GRAPH_H

#define MAX_SIZE 100

typedef struct {
    int vertex;
    Node* next;
} Node;

typedef struct {
    int numVertices;
    Node** adjLists;
} Graph;

void addEdges();
void addNode();
void createGraph();

#endif
