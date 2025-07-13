#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n;
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
    swap(&A[LB], &A[random_index]);
    int pivot = A[LB]; // Set the pivot element
    printf("PIVOT SELECTED : %d\n", pivot); // Display the pivot element
    int start = LB + 1;
    int end = UB;
    while (start <= end)
    {
        while (start <= UB && A[start] <= pivot)
            start++;
        while (A[end] > pivot)
            end--;
        if (start < end)
        {
            swap(&A[start], &A[end]);
        }
    }
    swap(&A[LB], &A[end]);
    print(A, n);
    return end;
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
