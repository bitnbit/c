#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    int a[5],c=0;
    srand(time(NULL));
    for(int i=0;i<5;++i)
    {
        a[i]=rand()%5+6;
    }
    for(int i=0;i<5;++i)
    {
        if(a[i]==7)
        {
           c++;
        }
    }
    if(c!=0)
    {
        printf("The number of 7 is %d. \n",c);
    }
    else
    {
        puts("7 is not found. ");
    }
}
