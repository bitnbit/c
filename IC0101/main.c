#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10];
    for(int i=0;i<10;++i)
    {
        a[i]=i;
    }
    for(int i=0;i<10;++i)
    {
        if(a[i]==6)
        {
            printf("The place of 6 in the array is %d.\n",i);
        }
    }
}
