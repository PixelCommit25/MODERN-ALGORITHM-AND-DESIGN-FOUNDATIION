#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int brute(char T[],char P[],int n,int m);
int main()
{
    int n,m,index;
    char na[100];
    char ma[100];
    printf("ENTER THE STRING T :");
    fgets(na, sizeof(na), stdin);
    na[strcspn(na,"\n")] = 0;
    n=strlen(na);
    printf("ENTER THE STRING TO BE SEARCHED IN T :");
    fgets(ma, sizeof(ma), stdin);
    ma[strcspn(ma,"\n")] = 0;
    m=strlen(ma);
    printf("THE SIZE OF THE STRING : %d AND THE SUBSTRING IS :%d",n,m);
    index=brute(na,ma,n,m);
    if(index==-1)
        printf("\nTHE STRING IS NOT PRESENT ");
    else
        printf("\nTHE STRING IS PRESENT FROM THE LOCATION %d TO %d",index+1,index+m);
    return 0;
}
int brute(char T[],char P[],int n,int m)
{
    for(int i=0; i<=n-m; i++)
    {
        int j=0;
        while( (j<m) && (P[j]==T[i+j]))
            j=j+1;
        if(j==m)
            return i;
    }
    return -1;
}
