#include <stdio.h>
#include <string.h>
// Define the invoice structure
struct invoice {
    int d;        // Day
    int m;        // Month
    int y;        // Year
    char na[20];  // Name
};
void mergesort(struct invoice a[], int low, int high);
void copy(struct invoice a[], struct invoice temp[], int low, int high);
void merge(struct invoice a[], struct invoice temp[], int low1, int high1, int low2, int high2);
void display(struct invoice e[], int n);

void mergesort(struct invoice a[], int low, int high)
{
    struct invoice temp[100];
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);                  // Sort the first half
        mergesort(a, mid + 1, high);             // Sort the second half
        merge(a, temp, low, mid, mid + 1, high); // Merge the two halves
        copy(a, temp, low, high);                // Copy sorted elements back
    }
}
void copy(struct invoice a[], struct invoice temp[], int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}
void merge(struct invoice a[], struct invoice temp[], int low1, int high1, int low2, int high2)
{
    int i = low1, j = low2, k = low1;
    while ((i <= high1) && (j <= high2))
    {
        if (a[i].y < a[j].y)
        {
            temp[k] = a[i];
            i++;
        }
        else if (a[i].y > a[j].y)
        {
            temp[k] = a[j];
            j++;
        }

        else if (a[i].m<a[j].m)
            {
                temp[k] = a[i];
                i++;
            }
        else if (a[i].m > a[j].m)
            {
                temp[k] = a[j];
                j++;
            }
        else if (a[i].d <a[j].d)
            {
                temp[k] = a[i];
                i++;
            }
        else if (a[i].d >a[j].d)
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
void display(struct invoice e[], int n)
{
    printf("\n==========================================\n");
    printf("| %-5s | %-15s | %-10s |\n", "No.", "Name", "Date");
    printf("==========================================\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %-5d | %-15s | %02d/%02d/%d |\n", i + 1, e[i].na, e[i].d, e[i].m, e[i].y);
    }

    printf("==========================================\n");
}

int main()
{
    struct invoice e[10];
    int n, i;
    // Get the number of invoices
    printf("ENTER THE NUMBER OF INVOICES YOU WANT TO ENTER: ");
    scanf("%d", &n);
    getchar(); // Clear the newline character left in the input buffer by scanf
    // Input the invoice details
    for (i = 0; i < n; i++) {
        printf("\nENTER THE DETAILS OF INVOICE NO. %d:\n", i + 1);
        // Get the name
        printf("ENTER THE NAME: ");
        fgets(e[i].na, sizeof(e[i].na), stdin);
        e[i].na[strcspn(e[i].na, "\n")] = '\0';  // Remove the trailing newline character
        // Get the year
        printf("ENTER THE YEAR: ");
        scanf("%d", &e[i].y);
        // Get the month
        printf("ENTER THE MONTH (1-12): ");
        scanf("%d", &e[i].m);
        while (e[i].m < 1 || e[i].m > 12)
        {
            printf("INVALID MONTH!! PLEASE TRY ENTERING A VALID MONTH (1-12): ");
            scanf("%d", &e[i].m);
        }
        printf("ENTER THE DAY (1-31): ");
        scanf("%d", &e[i].d);
        while (e[i].d < 1 || e[i].d > 31)
        {
            printf("INVALID DAY!! PLEASE TRY ENTERING A VALID DAY (1-31): ");
            scanf("%d", &e[i].d);
         printf("THE DEATAILS ENTERED : %-15s  %02d/%02d/%d ",e[i].na, e[i].d, e[i].m, e[i].y);
        }
        getchar(); // Clear the input buffer
    }
    mergesort(e,0,n-1);
    printf("THE LIST AFTER SORTING ");
    display(e,n);
    }

