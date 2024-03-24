#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 12
#define MAX_EDGES 20
// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};
// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};
// Global variables
struct Edge edges[MAX_EDGES];
struct Subset subsets[MAX_NODES];
// Function prototypes
int find(int i);
void unionSets(int x, int y);
void kruskal(int numNodes, int numEdges);
void sortEdges(int numEdges);

int main() {
    int numNodes = 12;
    int numEdges = 20;
    // Initialize edges (src, dest, weight)
    edges[0] = (struct Edge){0, 1, 6};
    edges[1] = (struct Edge){0, 2, 6};
     edges[2] = (struct Edge){0, 3, 6};
    edges[3] = (struct Edge){1, 4, 2};
    edges[4] = (struct Edge){1, 2, 1};
    edges[5] = (struct Edge){2, 3, 2};
    edges[6] = (struct Edge){2, 6, 2};
    edges[7] = (struct Edge){4, 2, 7};
    edges[8] = (struct Edge){4, 5, 4};
    edges[9] = (struct Edge){5, 6, 11};
    edges[10] = (struct Edge){3, 7, 18};
    edges[11] = (struct Edge){5, 8, 10};
    edges[12] = (struct Edge){8, 6, 22};
    edges[13] = (struct Edge){6, 9, 2};
    edges[14] = (struct Edge){9, 7, 1};
    edges[15] = (struct Edge){8, 9, 12};
    edges[16] = (struct Edge){8, 11, 25};
    edges[17] = (struct Edge){9, 11, 16};
    edges[18] = (struct Edge){7, 10, 8};
    edges[19] = (struct Edge){10, 11, 3};

    sortEdges(numEdges); // Sort the edges by their weights

    kruskal(numNodes, numEdges);

    return 0;
}
// Find set of an element i (uses path compression technique)
int find(int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets[i].parent);
    return subsets[i].parent;
}
// Union of two sets x and y (uses union by rank)
void unionSets(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);

    if (subsets[xRoot].rank < subsets[yRoot].rank)
        subsets[xRoot].parent = yRoot;
    else if (subsets[xRoot].rank > subsets[yRoot].rank)
        subsets[yRoot].parent = xRoot;
    else {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
}
// Bubble sort implementation to sort edges by their weights
void sortEdges(int numEdges) {
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = 0; j < numEdges - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                // Swap edges
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}
// Kruskal's algorithm to find the minimum spanning tree
void kruskal(int numNodes, int numEdges) {
    // Initialize subsets
    for (int i = 0; i < numNodes; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    // Initialize result
    struct Edge result[numNodes - 1];
    // Index to keep track of the sorted edges
    int sortedIndex = 0;
    // Index to traverse the result array
    int resultIndex = 0;
    // Total cost of the minimum spanning tree
    int totalCost = 0;

    while (resultIndex < numNodes - 1 && sortedIndex < numEdges) {
        struct Edge nextEdge = edges[sortedIndex++];

        int x = find(nextEdge.src);
        int y = find(nextEdge.dest);
        // If including this edge doesn't cause a cycle, add it to the result
        if (x != y) {
            result[resultIndex++] = nextEdge;
            unionSets(x, y);
            totalCost += nextEdge.weight;
        }
    }
    // Print the result
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < resultIndex; i++) {
        printf("(%d, %d) with weight %d\n", result[i].src, result[i].dest, result[i].weight);
    }
    // Print the total cost
    printf("Total Cost of Minimum Spanning Tree: %d\n", totalCost);
}
