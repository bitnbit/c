#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fact,i,n;//�������
    fact=1,i=1;

    printf("Enter a number: ");//��ʾ�û���������
    scanf("%d",&n);
    while(i<=n)//���н׳�����
    {
        fact=fact*i;
        i=i+1;
    }

    printf("Do enter the number(n): ""%d\n",n);//������
    printf("n!=%d\n",fact);

    return 0;
}
