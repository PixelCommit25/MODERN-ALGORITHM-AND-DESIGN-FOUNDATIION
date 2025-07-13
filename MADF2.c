#include<stdio.h>
int n;
void mergesort(int[],int,int,int);
void merge(int[],int[],int,int,int,int);
void copy(int[],int[],int,int);
void display(int[],int,int);
int main()
{
    int a[20],n,i,low,high;
    printf("ENTER THE NUMBER OF ELEMENTS IN THE ARRAY :");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("ENTER ELEMENT %d : ",i+1);
        scanf("%d",&a[i]);
    }
    low=0,high=n-1;
    mergesort(a,low,high,n);
    printf("SORTED ELEMENTS ARE : ");
    display(a,low,high);
    return 0;
}
void mergesort(int a[],int low,int high,int n)
{
    int temp[50],mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid,n);
        mergesort(a,mid+1,high,n);

        merge(a,temp,low,mid,mid+1,high);
        copy(a,temp,low,high);
        for(int i=0; i<n; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}
void merge(int a[],int temp[],int low1,int high1,int low2,int high2)
{
    int i=low1,j=low2,k=low1;
    while((i<=high1)&&(j<=high2))
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=a[j];
            j++,k++;
        }
    }
    while(i<=high1)
    {
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=high2)
    {
        temp[k]=a[j];
        j++;
        k++;
    }
}
void copy(int a[],int temp[],int low,int high)
{
    for(int i=low; i<=high; i++)
    {
        a[i]=temp[i];
    }
}
void display(int a[],int low,int high)
{
    for(int i=low; i<=high; i++)
    {
        printf(" %d ",a[i]);
    }
}
