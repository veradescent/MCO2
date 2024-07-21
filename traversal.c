#define MAX 256

typedef struct Queue {
  char items[MAX_VERTICES]{MAX_STRING_LENGTH];
  int front;
  int rear;
} Queue;

void enqueue(Queue* q, const char* value){
  if (q->rear == MAX_VERTICES - 1)
    return;
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    strcpy(q->items[q->rear], value);
  }
}

char* dequeue(Queue* q){
  char* item = malloc(MAX_STRING_LENGTH * sizeof(char));
  if (isEmpty(q)){
    item = NULL;
  } else {
    strcpy(item, q->items[q->front]);
    q->front++;
    if (q->front > q->rear){
      q->front = q->rear = -1;
    }
  }
  return item;
}

int isEmpty(Queue* q){
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

void BFS(Graph* graph, const char* startVertex, FILE* outputFile){
  Queue* q = malloc(sizeof(Queue));
  q->front = -1;
  q->rear = -1;

  int visited[MAX_VERTICES] = {0};
  int startIndex = getVertexIndex(graph, startVertex);
  visited[startIndex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)){
    char* currentVertex = dequeue(q);
    fprintf(outputFile, "%s ", currentVertex);
    int currentIndex = getVertexIndex(graph, currentVertex);

    Node* temp = graph->adjLists[currentIndex];
    while (temp){
      int adjIndex = getVertexIndex(graph, temp->vertex);
      if (!visited[adjIndex]){
        visited[adjIndex] = 1;
        enqueue(q, temp->vertex);
      }
      temp = temp->next;
    }
  }
  fprintf(outputFile, "\n");
}

void DFS(Graph* graph, const char* startVertex, int visited[], FILE* outputFile){
  int startIndex = getVertexIndex(graph, startVertex);
  Node* adjList = graph->adjLists[startIndex];
  Node* temp = adjList;

  visited[startIndex] = 1;
  fprintf(outputFile, "%s ", startVertex);

  while (temp != NULL){
    int adjIndex = getVertexIndex(graph, temp->vertex);
    if (!visited[adjIndex]){
      DFS(graph, temp->vertex, visited, outputFile);
    }
    temp = temp->next;
  }
}

