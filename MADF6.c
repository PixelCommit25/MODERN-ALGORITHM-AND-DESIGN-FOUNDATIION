#include <stdio.h>
#include <stdbool.h>
#define MAX 9999
#define SIZE 10
int mindist(bool S[], int dist[], int V)
{
    int min = MAX, min_index = -1;
    for (int v = 0; v < V; v++)
        {
        if (!S[v] && dist[v] < min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void printPath(int parent[], int j)
{
    if (parent[j] == -1)
    {
        printf("%d", j+1);
        return;
    }
    printPath(parent, parent[j]);
    printf(" - %d", j+1);
}
void display(int dist[], int parent[], int V)
{
    printf("SOURCE\tDESTINATION\tCOST\t\tPATH\n");
    for (int i = 0; i < V; i++)
        {
        printf("1\t%d\t\t", i+1);
        if (dist[i] == MAX)
            {
            printf("9999(NO PATH)\n");  // No path exists
        } else
        {
            printf("%d\t\t", dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
}
void dijkstra(int graph[SIZE][SIZE], int src, int V)
{
    int dist[SIZE];
    bool S[SIZE];
    int parent[SIZE];
    for (int i = 0; i < V; i++)
        {
        dist[i] = MAX;
        S[i] = false;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
        {
        int u = mindist(S, dist, V);
        if (u == -1) break;

        S[u] = true;

        for (int v = 0; v < V; v++) {
            if (!S[v] && graph[u][v] != MAX && dist[u] != MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    display(dist, parent, V);
}
int main()
{
    int V, i, j;
    int graph[SIZE][SIZE];
    int src;
    printf("ENTER THE NUMBER OF VERTICES (Max %d): ", SIZE);
    scanf("%d", &V);
    if (V > SIZE || V <= 0)
    {
        printf("Invalid number of vertices! Must be between 1 and %d.\n", SIZE);
        return 1;
    }
    printf("ENTER THE COST ADJACENCY MATRIX (ENTER 9999 FOR NO DIRECT CONNECTION):\n");
    for (i = 0; i < V; i++)
        {
        for (j = 0; j < V; j++)
         {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("ENTER THE SORCE VERTEX :");
    scanf("%d",&src);
    dijkstra(graph, src, V);
    return 0;
}
