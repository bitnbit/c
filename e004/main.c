#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,i,j,k;//输入数据

    num=100;//赋初值

    printf("All of the Narcissus few is: ");//提示用户输出的是什么

    while(num<=999)//判断
    {
        i=num/100;
        j=(num-i*100)/10;
        k=num%10;

        if(num==i*i*i+j*j*j+k*k*k)
        {
            printf("%d  ",num);//输出水仙花数
        }
        num=num+1;
    }

    return 0;
}
