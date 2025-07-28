#include <stdio.h>
#include <stdlib.h>

#define V 7  // number of vertices
#define E 12 // number of edges

struct Edge {
    int src, dest, weight;
};

// For Union-Find
int parent[V];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    struct Edge edges[E] = {
        {0, 1, 1}, {0, 3, 4},
        {1, 2, 2}, {1, 3, 6}, {1, 4, 4},
        {2, 4, 5}, {2, 5, 6},
        {3, 4, 3}, {3, 6, 4},
        {4, 5, 8}, {4, 6, 7},
        {5, 6, 3}
    };

    // Sort edges by weight (simple bubble sort for clarity)
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int minCost = 0;
    printf("Edges in MST:\n");
    for (int i = 0, count = 0; count < V - 1 && i < E; i++) {
        int u = find(edges[i].src);
        int v = find(edges[i].dest);

        if (u != v) {
            printf("%d - %d\t%d\n", edges[i].src, edges[i].dest, edges[i].weight);
            minCost += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }

    printf("Minimum Cost = %d\n", minCost);
    return 0;
}