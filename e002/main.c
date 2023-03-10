#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Score,Count,Number,Amount;//输入变量
    Amount=10;//赋初值
    Number=0;

    printf("Please input ten students’ test scores.\n");//提示用户输入数据的总量

    for(Count=1;Count<=Amount;Count++)//判断是否已经输入十个数据
    {
        printf("Please input student's score: ");//提示用户输入
        scanf("%d",&Score);
        if(Score>=60)//判断是否及格
        {
            Number=Number+1;
        }
    }

    printf("The number of passing students is: ""%d\n",Number);//输出结果

    return 0;
}
