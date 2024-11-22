#include <stdio.h>
#define MAX 100

int adj[MAX][MAX] = {0}; // Adjacency matrix
int visited[MAX];        // Visited array
int n = 5;               // Number of vertices (predefined)

// Function for Depth-First Search
void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1; // Mark the current node as visited

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// Function for Breadth-First Search
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;

    // Enqueue the starting vertex
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (adj[vertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

// Function to print the adjacency matrix
void printAdjacencyMatrix() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define a graph with 5 vertices and 6 edges
    // Edges: (0-1), (0-2), (1-3), (1-4), (2-4), (3-4)
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[1][4] = adj[4][1] = 1;
    adj[2][4] = adj[4][2] = 1;
    adj[3][4] = adj[4][3] = 1;

    // Print the adjacency matrix
    printAdjacencyMatrix();

    // Perform DFS
    printf("\nDFS Traversal: ");
    for (int i = 0; i < n; i++) visited[i] = 0; // Reset visited array
    DFS(0); // Start DFS from vertex 0
    printf("\n");

    // Perform BFS
    printf("BFS Traversal: ");
    for (int i = 0; i < n; i++) visited[i] = 0; // Reset visited array
    BFS(0); // Start BFS from vertex 0
    printf("\n");

    return 0;
}
