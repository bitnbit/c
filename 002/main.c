#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move(int n,char x,char y,char z);

int main()
{
    int n;
    char A='A',B='B',C='C';
    printf("Please input the number of disks: ");
    scanf("%d",&n);
    move(n,A,B,C);
}

void move(int n,char x,char y,char z)
{
    if(n==1)
    {
        printf("%c->%c\n",x,z);
    }
    else
    {
        move(n-1,x,z,y);
        printf("%c->%c\n",x,z);
        move(n-1,y,x,z);
    }
}
