#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define a structure for a graph node
struct Node
{
    int data;
    struct Node *next;
};

// Define a structure for a graph
struct Graph
{
    int vertices;
    struct Node **adjacencyList;
};

// Function to create a new graph
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (struct Node **)malloc(vertices * sizeof(struct Node *));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

// Function to display the graph visually
void displayGraph(struct Graph *graph)
{
    printf("Graph:\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        struct Node *current = graph->adjacencyList[i];
        printf("%d -> ", i);
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
            if (current != NULL)
            {
                printf("-> ");
            }
        }
        printf("\n");
    }
}

// Stack data structure for DFS
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool isFull(struct Stack *stack)
{
    return (stack->top == stack->capacity - 1);
}

bool isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    return stack->array[stack->top--];
}

// Depth-First Search
void DFS(struct Graph *graph, int startVertex)
{
    bool *visited = (bool *)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; i++)
    {
        visited[i] = false;
    }

    struct Stack *stack = createStack(graph->vertices);
    visited[startVertex] = true;
    push(stack, startVertex);

    while (!isEmpty(stack))
    {
        int currentVertex = pop(stack);
        printf("%d ", currentVertex);

        struct Node *temp = graph->adjacencyList[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->data;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                push(stack, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int vertices = 19;
    struct Graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 7);
    addEdge(graph, 3, 8);
    addEdge(graph, 4, 9);
    addEdge(graph, 4, 10);
    addEdge(graph, 5, 11);
    addEdge(graph, 5, 12);
    addEdge(graph, 6, 13);
    addEdge(graph, 6, 14);
    addEdge(graph, 7, 15);
    addEdge(graph, 7, 16);
    addEdge(graph, 8, 17);
    addEdge(graph, 8, 18);

    // displayGraph(graph);

    printf("\nDepth-First Search (DFS): ");

    clock_t start_time, end_time;
    double cpu_time_used;
    start_time = clock();

    DFS(graph, 0);

    end_time = clock(); // Record the end time

    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // Calculate time used in seconds
    printf("\n");
    printf("Time taken: %f seconds\n", cpu_time_used);
    printf("\n");

    return 0;
}
