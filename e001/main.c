#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Number1,Number2,MaxValue;//输入变量

    printf("Please input two numbers: ");//提示用户输入数字
    scanf("%d%d",&Number1,&Number2);

    if (Number1 == Number2)//判断
    {
        printf("The numbers are the same.\n");//输出结果
    }

    else
    {
        if (Number1>Number2)
        {
            MaxValue=Number1;
        }

        else
        {
            MaxValue=Number2;
        }
        printf("The numbers are: ""%d,%d\n",Number1,Number2);//输出结果
        printf("The larger number is: ""%d\n",MaxValue);

    }
    return 0;
}
