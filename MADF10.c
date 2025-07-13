EXP 10
//CODE:SUM OF SUBSET PROBLEM
#include <stdio.h>
int X[10];
int w[10];
void sos(int s, int k, int r, int m, int n);
int main()
{
    int n, k, r, m, s = 0, i;
    printf("ENTER THE SUM OF WEIGHTS: ");
    scanf("%d", &m);
    printf("ENTER THE NUMBER OF ELEMENTS: ");
    scanf("%d", &n);
    printf("ENTER THE WEIGHTS:\n");
    for(i = 0; i < n; i++)
    {
        printf("ENTER W%d: ", i + 1);
        scanf("%d", &w[i]);
        s = s + w[i];
    }
    r = s;
    sos(0, 0, r, m, n);
    return 0;
}
void sos(int s, int k, int r, int m, int n)
{

    if (s == m)
    {
        printf("Solution vector: ");
        printf("(");
        for (int i = 0; i < n; i++) {
            printf("X%d", i + 1);
            if (i < n - 1)
                printf(", ");
        }
        printf(") = (");
        for (int i = 0; i < n; i++) {
            printf("%d", X[i]);
            if (i < n - 1)
                printf(", ");
        }
        printf(")\n");
        return;
    }
    if (k >= n)
    {
        return;
    }
    if (s + w[k] <= m)
    {
        X[k] = 1;
        sos(s + w[k], k + 1, r - w[k], m, n);
    }
    X[k] = 0;
    sos(s, k + 1, r - w[k], m, n);
}
