#include <stdio.h>
#include <stdlib.h>

int SEARCH(int Data[],int low,int high,int key);

int main()
{
    int a[10]={22,85,67,34,13,96,55,4,36,78},b;
    printf("The original array is ");
    for(int i=0;i<10;++i)
    {
        printf("%d ",a[i]);
    }
    puts("\n");
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<9;++j)
        {
            if(a[j]>a[j+1])
            {
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("The array in ascending order is ");
    for(int i=0;i<10;++i)
    {
        printf("%d ",a[i]);
    }
    puts("\n");
    printf("Please enter the number you want to search: ");
    scanf("%d",&b);

    int index;
    index=SEARCH(a,0,10,b);
    if(index==-1)
    {
        printf("The number is not found.\n");
    }
    else
    {
        printf("\nThe place of the number is %d.\n",index+1);
    }
}

int SEARCH(int Data[],int low,int high,int b)
{
    int mid=(low+high)/2;
    if(low<=high)
    {
        if(b==Data[mid])
        {
            return mid;
        }
        else if(b>Data[mid])
        {
            return SEARCH(Data,mid+1,high,b);
        }
        else
        {
            return SEARCH(Data,low,mid-1,b);
        }
    }
    else
    {
        return -1;
    }
}
