#ifndef GRAPH_H
#define GRAPH_H

#define MAX_VERTICES 100
#define MAX_STRING_LENGTH 100

typedef struct {
    char vertex[MAX_STRING_LENGTH];
    Node* next;
} Node;

typedef struct {
    int numVertices;
    Node** adjLists;
    char** vertices;
} Graph;

Graph* createGraph(int vertices);
Node* createNode(const char* vertex);
int getVertexIndex(Graph* graph, const char* vertex);
void addEdge(Graph* graph, const char* src, const char* dest);

#endif
