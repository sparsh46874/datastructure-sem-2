#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge to adjacency list (sorted insertion)
void addEdge(struct Node* adj[], int src, int dest) {
    struct Node* newNode = createNode(dest);

    // Insert in sorted order (ascending)
    if (adj[src] == NULL || adj[src]->vertex > dest) {
        newNode->next = adj[src];
        adj[src] = newNode;
    } else {
        struct Node* temp = adj[src];
        while (temp->next != NULL && temp->next->vertex < dest) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// DFS function
void DFS(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(adjVertex, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // Create adjacency list
    struct Node* adj[V];
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(adj, src, dest);
    }

    int start;
    scanf("%d", &start);

    int visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // Perform DFS
    DFS(start, adj, visited);

    return 0;
}