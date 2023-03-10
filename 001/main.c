#include <stdio.h>
#include <stdlib.h>

int judge(int k);

int main()
{
    int k,p=0;
    printf("Please input an integer: ");
    scanf("%d",&k);
    puts("");

    if(k<=1)
    {
        puts("Error!");
        return 0;
    }
    else
    {
        p=judge(k);
        if(p==1)
        {
            printf("%d is prime number.\n",k);
        }
        else
        {
            printf("%d is not prime number.\n",k);
        }
    }
}

int judge(int k)
{
    int p=1;
    for(int i=2;i<=(k/2);++i)
    {
        if(k%i==0)
        {
            p=0;
            break;
        }
    }
    return p;
}
