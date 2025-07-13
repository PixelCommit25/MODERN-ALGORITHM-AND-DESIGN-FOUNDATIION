#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int A[100];

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int LB, int UB)
{
    int random_index = LB + rand() % (UB - LB + 1);
    swap(&A[UB], &A[random_index]); // Swap random pivot with high element
    int pivot = A[UB];              // Set the pivot element
    printf("PIVOT SELECTED : %d\n", pivot); // Display the pivot element

    int i = LB - 1;
    for (int j = LB; j < UB; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[UB]);
    return i + 1;
}

void quicksort(int A[], int LB, int UB)
{
    if (LB < UB)
    {
        int loc = partition(A, LB, UB);
        quicksort(A, LB, loc - 1);
        quicksort(A, loc + 1, UB);
    }
}

int main()
{
    int n;
    printf("ENTER THE NUMBER OF ELEMENTS IN THE ARRAY: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("ENTER THE %d ELEMENT: ", i + 1);
        scanf("%d", &A[i]);
    }
    srand(time(0));
    quicksort(A, 0, n - 1);
    printf("THE SORTED ELEMENTS ARE: ");
    print(A, n);
    return 0;
}

