#include <stdio.h>
#define MAX 20

int w[MAX][MAX], c[MAX][MAX], r[MAX][MAX];
int find(int c[MAX][MAX], int r[MAX][MAX], int i, int j)
{
    int min = 9999;
    int l;
    for (int m = r[i][j - 1]; m <= r[i + 1][j]; m++)
    {
        if (c[i][m - 1] + c[m][j] < min)
        {
            min = c[i][m - 1] + c[m][j];
            l = m;
        }
    }
    return l;
}
void print(int c[MAX][MAX], int w[MAX][MAX], int r[MAX][MAX], int n) {
    printf("\nWeight Matrix (W):\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j >= i)
                printf("%d\t", w[i][j]);
            else
                printf("\t");
        }
        printf("\n");
    }
    printf("\nCost Matrix (C):\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j >= i)
                printf("%d\t", c[i][j]);
            else
                printf("\t");
        }
        printf("\n");
    }
    printf("\nRoot Matrix (R):\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j >= i)
                printf("%d\t", r[i][j]);
            else
                printf("\t");
        }
        printf("\n");
    }
}
void obst(int p[], int q[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        w[i][i] = q[i];
        c[i][i] = 0;
        r[i][i] = 0;

        if (i < n)
        {
            w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
            r[i][i + 1] = i + 1;
            c[i][i + 1] = w[i][i + 1];
        }
    }
    for (int m = 2; m <= n; m++)
    {
        for (int i = 0; i <= n - m; i++)
        {
            int j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            int k = find(c, r, i, j);
            c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
            r[i][j] = k;
        }
    }
    print(c, w, r, n);
}
int main()
{
    int n, i;
    int p[MAX], q[MAX];
    printf("ENTER THE NUMBER OF ELEMENTS: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("ENTER THE ELEMENTS P%d: ", i);
        scanf("%d", &p[i]);
    }
    for (i = 0; i <= n; i++)
    {
        printf("ENTER THE FREQUENCY Q%d: ", i);
        scanf("%d", &q[i]);
    }
    obst(p, q, n);
    return 0;
}
