#include <stdio.h>
#include <limits.h>

#define V 5  

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the current state of distances and visited vertices
void printStep(int step, int selected, int dist[], int visited[]) {
    printf("Step %d:\n", step);
    printf("  Selected Vertex: %d\n", selected);
    printf("  Distances: ");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
    printf("\n  Remaining: ");
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            printf("%d ", i);
    }
    printf("\n\n");
}

// Function to print final shortest distances
void printFinalDistances(int dist[]) {
    printf("Final Shortest Distances from Source:\n");
    printf("Vertex \t Distance\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

// Dijkstra's algorithm with step-by-step output
void dijkstra(int graph[V][V], int src) {
    int dist[V];       // dist[i] will hold the shortest distance from src to i
    int visited[V];    // visited[i] will be true if vertex i is processed

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;  // Distance from source to itself is always 0

    printf("Dijkstra's Algorithm Step-by-Step:\n\n");

    for (int step = 1; step <= V; step++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        // Print current step
        printStep(step, u, dist, visited);

        // Update distance value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printFinalDistances(dist);
}

// Main function
int main() {
    int graph[V][V] = {
        {0, 9, 75, 0, 0},
        {0, 0, 95, 0, 42},
        {0, 0, 0, 51, 0},
        {0, 19, 0, 0, 0},
        {0, 0, 0, 31, 0}
    };

    int source = 0;
    dijkstra(graph, source);

    return 0;
}