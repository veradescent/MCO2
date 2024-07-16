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

typedef struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void addEdges();
void addNode();
void createGraph();
void insertNode();
void deleteNode();

#endif
