#include <stdio.h>

Graph* createGraph(int vertices){
  Graph* graph = malloc(sizeof(Graph));
  graph->numVertices = vertices;
  graph->adjLists = malloc(vertices * sizeof(Node*));
  graph->vertices = malloc(vertices* sizeof(char*));

  for (int i = 0; i < vertices; i++){
    graph->adjLists[i] = NULL;
    graph->vertices[i] = malloc(MAX_STRING_LENGTH * sizeof(char));
  }

  return graph;
}

Node* createNode(const char* vertex){
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->vertex, vertex);
  newNode->next = NULL;
  return newNode;
}

int getVertexIndex(Graph* graph, const char* vertex){
  for (int i = 0; i < graph->numVertices; i++){
    if (strcmp(graph->vertices[i], vertex) == 0){
      return i;
    }
  }

void addEdge(Graph* graph, const char* src, const char* dest){
  int srcIndex = getVertexIndex(graph, src);
  int destIndex = getVertexIndex(graph, dest);

  if (srcIndex == -1){
    srcIndex = graph->numVertices++;
    strcpy(graph->vertices[srcIndex], src);
  }

  if (destIndex == -1){
    destIndex = graph->numVertices++;
    strcpy(graph->vertices[destIndex], dest);
  }
  
  Node* newNode = createNode(dest);
  newNode->next = graph->adjLists[srcIndex];
  graph->adjLists[srcIndex] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adjLists[destIndex];
  graph->adjLists[destIndex] = newNode;
}
}
