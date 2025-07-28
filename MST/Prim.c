#include<stdio.h>
#include<limits.h>

#define V 7

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
    visited[0] = 1;

    int min_cost=0;
    int edge = 0;

    while(edge < V-1){
        int x = 0, y =0;
        int min = INT_MAX;

        for(int i=0; i< V ; i++)
        {
            if(visited[i] == 1)
            {
                for(int j = 0; j< V; j++)
                {
                    if(visited[j] == 0 && graph[i][j] != 0)
                    {
                        if(graph[i][j] < min){
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d \t %d \n",x,y,graph[x][y]);
        min_cost += graph[x][y];
        visited[y] =1;
        edge++;
    }
    printf("min cost = %d",min_cost);
}