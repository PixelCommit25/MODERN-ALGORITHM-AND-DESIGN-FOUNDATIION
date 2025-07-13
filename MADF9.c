#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int LCS(char X[], char Y[], int n, int m, char lcs[], int L[20][20]);
void printLCSTable(int L[20][20], int n, int m);

int main()
{
    char X[20], Y[20], lcs[20];
    int m, n;
    int L[20][20];

    printf("ENTER THE FIRST STRING: ");
    fgets(X, sizeof(X), stdin);
    X[strcspn(X, "\n")] = 0;
    n = strlen(X);

    printf("ENTER THE SECOND STRING: ");
    fgets(Y, sizeof(Y), stdin);
    Y[strcspn(Y, "\n")] = 0;
    m = strlen(Y);

    int result = LCS(X, Y, n, m, lcs, L);
    printf("Length of Longest Common Subsequence: %d\n", result);


    printf("LCS Table:\n");
    printLCSTable(L, n, m);


    printf("Longest Common Subsequence: %s\n", lcs);

    return 0;
}

int LCS(char X[], char Y[], int n, int m, char lcs[], int L[20][20])
{

    for (int i = 0; i <= n; i++)
        L[i][0] = 0;
    for (int j = 0; j <= m; j++)
        L[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }


    int index = L[n][m];
    lcs[index] = '\0';

    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    return L[n][m];
}

void printLCSTable(int L[20][20], int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            printf("%d ", L[i][j]);
        }
        printf("\n");
    }
}

