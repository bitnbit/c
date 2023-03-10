#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10]={22,85,67,34,13,96,55,4,36,78};
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
    puts("");
}
