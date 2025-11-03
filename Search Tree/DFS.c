#include <stdio.h>
#define V 7

void dfs(int graph[V][V], int visited[V], int current) {
    printf("%d ", current);
    visited[current] = 1;

    for(int i = 0; i < V; i++) {
        if(graph[current][i] && !visited[i]) {
            dfs(graph, visited, i);
        }
    }
}

int main(){

    int graph[V][V] = {
        {0, 1, 0, 4, 0, 0, 0},
        {1, 0, 2, 6, 4, 0, 0},
        {0, 2, 0, 0, 5, 6, 0},
        {4, 6, 0, 0, 3, 0, 4},
        {0, 4, 5, 3, 0, 8, 7},
        {0, 0, 6, 0, 8, 0, 3},
        {0, 0, 0, 4, 7, 3, 0},
    };

    int visited[V] = {0};

    printf("DFS Traversal starting from node 0:\n");
    dfs(graph, visited, 0);

    return 0;
}