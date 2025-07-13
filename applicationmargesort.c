#include <stdio.h>
#include <string.h>
#define MAX 100
struct student
{
    char na[50];  // Name
    char g;       // Grade
};
void display(struct student s[], int n)
{
    printf("=============================================\n");
    printf("| %-5s | %-25s | %-5s |\n", "No.", "Name", "Grade");
    printf("=============================================\n");
    for (int i = 0; i < n; i++)
    {
        printf("| %-5d | %-25s | %-5c |\n", i + 1, s[i].na, s[i].g);
    }
    printf("=============================================\n");
}
char getgrade(int n)
{
    if (n >= 90)
        return 'A';
    else if (n >= 80)
        return 'B';
    else if (n >= 70)
        return 'C';
    else if (n >= 60)
        return 'D';
    else if (n >= 50)
        return 'E';
    else
        return 'F';
}
void copy(struct student a[], struct student temp[], int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}
void merge(struct student a[], struct student temp[], int low1, int high1, int low2, int high2)
{
    int i = low1, j = low2, k = low1;
    while ((i <= high1) && (j <= high2))
    {
        if (a[i].g < a[j].g)
        {
            temp[k] = a[i];
            i++;
        }
        else if (a[i].g > a[j].g)
        {
            temp[k] = a[j];
            j++;
        }
        else
        {
            if (strcmp(a[i].na, a[j].na) < 0)
            {
                temp[k] = a[i];
                i++;
            }
            else
            {
                temp[k] = a[j];
                j++;
            }
        }
        k++;
    }
    while (i <= high1)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= high2)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
}
void mergesort(struct student a[], int low, int high)
{
    struct student temp[MAX];
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);                  // Sort the first half
        mergesort(a, mid + 1, high);             // Sort the second half
        merge(a, temp, low, mid, mid + 1, high); // Merge the two halves
        copy(a, temp, low, high);                // Copy sorted elements back
    }
}
int main()
{
    int i, n, percentage;
    struct student s[MAX];
    printf("ENTER THE NUMBER OF STUDENTS YOU WANT TO ENTER: ");
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        printf("\nENTER THE DETAILS OF STUDENT %d\n", i + 1);
        printf("ENTER THE NAME OF THE STUDENT: ");
        fgets(s[i].na, sizeof(s[i].na), stdin);
        s[i].na[strcspn(s[i].na, "\n")] = '\0';  // Remove newline character
        printf("ENTER THE PERCENTAGE OF THE STUDENT: ");
        scanf("%d", &percentage);
        getchar();  // Clear the newline character left by scanf
        s[i].g = getgrade(percentage);
        printf("THE GRADE OF STUDENT %s IS: %c\n", s[i].na, s[i].g);
    }
    printf("\nTHE DETAILS GIVEN BY THE USER:\n");
    display(s, n);
    mergesort(s, 0, n - 1);
    printf("\nTHE LIST AFTER SORTING BY GRADE AND NAME:\n");
    display(s, n);
    return 0;
}
