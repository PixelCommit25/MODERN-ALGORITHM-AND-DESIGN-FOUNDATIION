#include <stdio.h>
#define MAX 100
#define INF 9999
int parent[MAX];
int find(int i)
{
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}
void un(int j, int k)
{
    if (j < k)
        parent[j] = k;
    else
        parent[k] = j;
}
// Function to implement Kruskal's Algorithm
void kruskal(int cost[MAX][MAX], int n)
{
    int mincost = 0; // Minimum cost of spanning tree
    int i, j, u,k, v, min;
    for (i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    i = 0;
    while (i < n - 1)
    {
        min = INF;
        u = -1;
        v = -1;
        for (j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (cost[j][k] < min)
                {
                    min = cost[j][k];
                    u = j;
                    v = k;
                }
            }
        }
        j = find(u);
        k = find(v);
        if (j != k)
        {
            i = i + 1;
            printf("\nEDGE %d - %d WITH COST %d\n", u+1, v+1, min);
            mincost += min;
            un(j, k);
        }
        cost[u][v] = cost[v][u] = INF;
    }
    printf("TOTAL MINIMUM COST: %d\n", mincost);
}
int main() {
    int cost[MAX][MAX] = {
        {INF, 7,   5,   INF, INF, INF, INF},
        {7,   INF, 8,   2,   6,   INF, INF},
        {5,   8,   INF, INF, INF, 4,   INF},
        {INF, 2,   INF, INF, INF, 1,   INF},
        {INF, 6,   INF, INF, INF, INF, 3},
        {INF, INF, 4,   1,   INF, INF, 6},
        {INF, INF, INF, INF, 3,   6,   INF}
    };

    int n = 7;
    kruskal(cost, n);
    return 0;
}

