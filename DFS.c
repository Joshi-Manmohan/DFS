#include <stdio.h>

#define MAX_NODES 100

int adjMatrix[MAX_NODES][MAX_NODES]; // Adjacency Matrix
int visited[MAX_NODES]; // To keep track of visited nodes

// Function to add an edge to the graph
void addEdge(int u, int v) {
adjMatrix[u][v] = 1;
adjMatrix[v][u] = 1; // Since the graph is undirected
}

// DFS function
void DFS(int node) {
printf("%d ", node); // Visit the node
visited[node] = 1;

for (int i = 0; i < MAX_NODES;
i++) {
if(!visited[i]&&adjMatrix[node][i]) { // Check if adjacent and not visited
        DFS(i);
}
}
}

// Menu-driven program
int main() {
int choice, u, v, startNode;

do{
printf("\n1. Add Edge\n");
printf("2. Perform DFS\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) { case 1:
printf("Enter two nodes to connect: ");
scanf("%d %d", &u, &v);
addEdge(u, v);
break;
case 2:
printf("Enter the starting node for DFS: ");
scanf("%d", &startNode);
visited[startNode] = 1; // Mark the starting node as visited

DFS(startNode);
printf("\n");
break;
case 3:
printf(“exiting”);
break;
default:
printf("Invalid choice!\n");
}
}while(choice!=3);

return 0;
}

