#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int p[101], w[101], t[10][10],k[10][10];
bool soln[100];
void knap(int, int, int[],  int[]);
void display(int, int);
void sel(int, int);
int main()
{
    int n, m;
    printf("ENTER THE NUMBER OF ITEMS: ");
    scanf("%d", &n);
    printf("ENTER THE TOTAL CAPACITY OF THE BAG: ");
    scanf("%d", &m);

    printf("ENTER THE WEIGHTS:\n");
    for (int i = 0; i < n; i++)
    {
        printf("ENTER W%d: ", i + 1);
        scanf("%d", &w[i]);
    }

    printf("ENTER THE PROFITS:\n");
    for (int i = 0; i < n; i++)
    {
        printf("ENTER P%d: ", i + 1);
        scanf("%d", &p[i]);
    }

    knap(n, m, p, w);
    return 0;
}

void knap(int n, int cap, int p[], int w[])
{
    int i, j;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= cap; j++)
        {
            if (i == 0 || j == 0)
            {
                k[i][j] = 0;
            }
            else if (w[i - 1] <= j)
            {
                k[i][j] = (p[i - 1] + k[i - 1][j - w[i - 1]] > k[i - 1][j])
                          ? p[i - 1] + k[i - 1][j - w[i - 1]]
                          : k[i - 1][j];
            }
            else
            {
                k[i][j] = k[i - 1][j];
            }
            t[i][j] = k[i][j];
        }
    }

    printf("\nTHE MAX PROFIT IS: %d\n\n", k[n][cap]);
    display(cap, n);

    printf("\n\nTHE ITEMS INCLUDED ARE: ");
    sel(n, cap);
}
void display(int cap, int n)
{
    printf("    ");
    for (int j = 0; j <= cap; j++)
    {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i <= n; i++)
    {
        printf("|%d| ", i);
        for (int j = 0; j <= cap; j++)
        {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
}
void sel(int i, int j)
{
    int a = i;
    while (i > 0 && j > 0)
    {
        if (k[i][j] != k[i - 1][j])
        {
            printf("%d ", i);
            soln[i] = true;
            j -= w[i - 1];
        }
        i--;
    }

    printf("\nTHE SOLUTION IS :\n(");
    for (int n = 1; n <= a; n++)
    {
        printf("X%d", n);
        if (n < a) printf(", ");
    }
    printf(") = (");

    for (int n = 1; n <= a; n++)
    {
        printf("%d", soln[n] ? 1 : 0);
        if (n < a) printf(", ");
    }
    printf(")\n");
}
