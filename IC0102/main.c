#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5],find=0;
    puts("Please enter 5 integers: ");
    for(int i=0;i<5;++i)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<5;++i)
    {
        if(a[i]==8)
        {
            printf("The place of 8 in the array is %d. \n",i+1);
            find=1;
        }
    }
    if(find==0)
    {
        printf("8 not found.");
    }
}
