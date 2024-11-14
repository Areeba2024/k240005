#include<stdio.h>
void horizontal_histogram(int element[],int count)
{
    int i,j;
    for(i=0;i<count;i++)
    {
    printf("Value %d:",i+1);
    for(j=0;j<element[i];j++)
    {
    printf("*");
    }
    printf("\n");
    }
}//end horizontal histogram

void vertical_histogram(int element[],int count)
{
    int max = element[0];
    int i,j;
    for(i=0;i<count;i++)
    {
        if(element[i] > max)
        {
            max = element[i];
        }
    }
    for(i=max;i>0;i--)
    {
        for(j=0;j<count;j++)
        {
            if(element[j] >=i)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    for(i=0;i<count;i++)
    {
        printf("%d ",element[i]);
    }
}//end vertical histogram


int main()
{
    int count,i,j;
    printf("Enter the count: ");
    scanf("%d",&count);
    int element[count];
    for(i=0;i<count;i++)
    {
    printf("Enter the element %d: ",i+1);
    scanf("%d",&element[i]);
    }
    
    printf("Horizontal Histogram\n");
    horizontal_histogram(element,count);
    printf("Vertical Histogram\n");
    vertical_histogram(element,count);
    return 0;
}