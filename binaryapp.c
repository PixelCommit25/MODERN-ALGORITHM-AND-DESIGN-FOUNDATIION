#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

struct student
{
    int roll;
    char name[50];
    char dept[15];
};
void display(struct student s[], int n)
{
    printf("\n%-15s %-30s %-10s\n", "Roll Number", "Name", "Department");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%-15d %-30s %-10s\n", s[i].roll, s[i].name, s[i].dept);
    }
}

void sortByName(struct student s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(s[j].name, s[j + 1].name) > 0)
            {
                struct student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int binarySearchByName(struct student s[], int n, char name[])
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cmp = strcmp(s[mid].name, name);
        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int bsroll(struct student s[], int n, int r)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (r < s[mid].roll)
            high = mid - 1;
        else if (r > s[mid].roll)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int i, j, n, x, index, choice;
    char searchName[50];
    struct student s[MAX];

    printf("\nENTER THE NUMBER OF STUDENTS YOU WANT TO ENTER :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("ENTER THE DETAILS OF STUDENT %d", i + 1);
        printf("\nENTER THE ROLL NUMBER OF THE STUDENT :");
        scanf("%d", &s[i].roll);
        getchar();

        printf("ENTER THE NAME OF THE STUDENT :");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = 0;

        printf("ENTER THE DEPARTMENT OF THE STUDENT :");
        fgets(s[i].dept, sizeof(s[i].dept), stdin);
        s[i].dept[strcspn(s[i].dept, "\n")] = 0;
    }
    printf("\n***********DISPLAYING THE ENTERED DETAILS:**************\n");
    display(s, n);

    // Sort by roll number
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (s[j].roll > s[j + 1].roll)
            {
                struct student t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }
    printf("\n***********DISPLAYING LIST ROLLNUMBERWISE:**************\n");
    display(s, n);

    do
    {
        printf("\n***MENU***");
        printf("\n1:SEARCH BASED ON ROLL NUMBER\n2:SEARCH BY NAME\n3:EXIT \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("ENTER THE ROLL NUMBER TO BE SEARCHED :");
            scanf("%d", &x);
            index = bsroll(s, n, x);
            if (index == -1)
                printf("THE RECORD DOES NOT EXIST ");
            else
            {
                printf("\n");
                printf("%-15d %-30s %-10s\n", s[index].roll, s[index].name, s[index].dept);
            }
            break;
        }
        case 2:
        {
            // Sort by name
            sortByName(s, n);
            printf("\n***********DISPLAYING LIST NAMEWISE:**************\n");
            display(s, n);

            printf("ENTER THE NAME TO BE SEARCHED :");
            getchar(); // Clear buffer
            fgets(searchName, sizeof(searchName), stdin);
            searchName[strcspn(searchName, "\n")] = 0;

            index = binarySearchByName(s, n, searchName);
            if (index == -1)
                printf("THE RECORD DOES NOT EXIST ");
            else
            {
                printf("\n");
                printf("%-15d %-30s %-10s\n", s[index].roll, s[index].name, s[index].dept);
            }
            break;
        }
        case 3:
        {
            printf("EXITED\n");
            exit(0);
            break;
        }
        default:
            printf("YOU ENTERED THE WRONG CHOICE \n");
        }
    } while (choice != 3);

    return 0;
}
