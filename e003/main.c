#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fact,i,n;//输入变量
    fact=1,i=1;

    printf("Enter a number: ");//提示用户输入数据
    scanf("%d",&n);
    while(i<=n)//进行阶乘运算
    {
        fact=fact*i;
        i=i+1;
    }

    printf("Do enter the number(n): ""%d\n",n);//输出结果
    printf("n!=%d\n",fact);

    return 0;
}
