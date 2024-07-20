#include <stdio.h>
#include <stdbool.h>

// String typedef

bool startVertexExists(String input, String vertices[], int n){
  bool result = false;

  for (int i = 0; i < n; i++){
    if (strcmp(input, vertices[i]) == 0){
      result = true;
    }
  }

  return result;
}

void calculateDegrees(){
}

int main (){
  String input;
  String startVertex;
  String vertices[MAX];
  int numOfVertices;
  FILE* inputFile;
  FILE* outputFile;

  printf("Input filename: ");
  scanf("%s", input);

  inputFile = fopen(input, "r");
  if (inputFile == NULL){
    printf("%s not found", inputd);
    return 1;
  }

  printf("Input start vertex for the traversal: ");
  scanf("%s", startVertex);

  // read number of vertices and create graph
  // add to array of vertices, add edge if string until it reaches -1
  // iterate acc to num of vertices
  fclose(inputFile);
  
  for (){
    // iterate through array of vertices, until it finds the start vertex
  }
  
  if (!startVertexExists(startVertex, vertices, numOfVertices)){ // start vertex does not exist
    printf("%s not found", startVertex);
    return 1;
  }

  int degrees[MAX] = {0};
  calculateDegrees();

  outputFile = fopen("TRAVERSALS.TXT", "w");
  for (int i = 0; i < numOfVertices; i++){ // num of vertices
    fprintf(outputFile, "%s  %d\n", vertices[i], degrees[i]);
  }

  BFS();
  DFS();

  fclose(outputFile);
  return 0;
}
