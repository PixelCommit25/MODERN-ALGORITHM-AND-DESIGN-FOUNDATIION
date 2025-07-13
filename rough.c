
#include <stdio.h>
int A[100];
int n;
int partition(int[],int,int);
void quicksort(int[],int,int);
void print(int[],int);
int main()
{
printf("ENTER THE NUMBER OF ELEMENTS IN THE ARRAY: ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
printf("ENTER THE %d ELEMENT: ", i + 1);
scanf("%d", &A[i]);
}
int low = 0;
int up = n - 1;
quicksort(A, low, up);
printf("THE SORTED ELEMENTS ARE: ");
print(A, n);
return 0;
}
void quicksort(int A[], int LB, int UB)
{
if (LB < UB)
{
int loc = partition(A,LB,UB);
quicksort(A,LB,loc-1);
quicksort(A,loc+1,UB);
}
}
int partition(int A[], int LB, int UB)
{
int t;
int pivot=LB;
int start=LB;
int end=UB;
while (start<end)
{
while(A[start]<=A[pivot]&&start < end)
start++;
while (A[end]>A[pivot])
end--;
if (start<end)
{
t = A[start];
A[start] = A[end];
A[end] = t;
}
}
t = A[LB];
A[LB] = A[end];
A[end] = t;
print(A, n);
return end;
}
void print(int A[], int n)
{
for (int i = 0; i < n; i++)
{
printf("%d ", A[i]);
}
printf("\n");
}
