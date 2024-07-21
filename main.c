#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef char String[MAX_SIZE];

bool startVertexExists(String input, String vertices[], int n){
  bool result = false;

  for (int i = 0; i < n; i++){
    if (strcmp(input, vertices[i]) == 0){
      result = true;
    }
  }

  return result;
}

void calculateDegrees(Graph* graph, int degrees[]){
  for (int i = 0; i < graph->numVertices; i++){
    Node* temp = graph->adjLists[i];
    while (temp){
      degrees[i]++;
      temp = temp->next;
    }
  }
}

int main (){
  String input;
  FILE* inputFile;
  FILE* outputFile;

  printf("Input filename: ");
  scanf("%s", input);

  inputFile = fopen(input, "r");
  if (inputFile == NULL){
    printf("%s not found", input);
    return 1;
  }

  String startVertex;
  printf("Input start vertex for the traversal: ");
  scanf("%s", startVertex);

  int numVertices;
  fscanf(inputFile, "%d", &numVertices);
  Graph* graph = createGraph(numVertices);

  String src, dest;
  for (int i = 0; i < numVertices; i++){
    fscanf(inputFile, "%s ", src);
    
    if () // -1
      dest = NULL;
    else
      fscanf(inputFile, "%s ", dest);
    
    addEdge(graph, src, dest);
  }

  fclose(inputFile);
  
  if (!startVertexExists(startVertex, vertices, numOfVertices)){ // start vertex does not exist
    printf("%s not found", startVertex);
    return 1;
  }

  int degrees[MAX] = {0};
  calculateDegrees(graph, degrees);
  
  outputFile = fopen("TRAVERSALS.TXT", "w");
  for (int i = 0; i < numOfVertices; i++){ // num of vertices
    fprintf(outputFile, "%s  %d\n", graph->vertices[i], degrees[i]);
  }

  BFS(graph, graph->vertices[0], outputFile);

  int visited[MAX_VERTICES] = {0};
  DFS(graph, graph->vertices[0], visited, outputFile);

  fclose(outputFile);
  return 0;
}
