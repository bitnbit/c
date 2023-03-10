#include <stdio.h>
#include <stdlib.h>

int Fib(int a);

int main()
{
    int Num;
    int i;
    printf("Enter a number: ");
    scanf("%d",&Num);
    for(i=1;i<Num;i++)
    {
        printf("%d",Fib(i));
        if(i<Num-1)
        {
            printf(",");
        }
    }
}

int Fib(int a)
{
    if(a<=2)
    {
        return 1;
    }
    else
    {
        return Fib(a-1)+Fib(a-2);
    }
}
