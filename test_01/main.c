#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

void (*t)();
void copy();
void upper();
void lower();
void comparison();
void calculation();

int main(void)
    {
    int option=0;
    printf("1: 复制字符\n"
           "2: 将字符全部转换为大写\n"
           "3: 将字符全部转换为小写\n"
           "4: 将两串字符进行大小比较\n"
           "5: 运行计算器程序\n");
    printf("请输入你的选择: ");
    scanf("%d",&option);
    if(option==1)
    {
        t=&copy;
        (*t)();
    }
    else if(option==2)
    {
        t=&upper;
        (*t)();
    }
    else if(option==3)
    {
        t=&lower;
        (*t)();
    }
    else if(option==4)
    {
        t=&comparison;
        (*t)();
    }
    else if(option==5)
    {
        t=&calculation;
        (*t)();
    }
    else{puts("错误!");};
    }

void copy()
{
    char string1[21]="The wheel of fortune";
    char * string2[21];
    printf("原始字符串是: %s\n",string1);
    string2[0]=&string1;
    printf("复制而来的字符串是: %s\n",*string2);
}

void upper()
{
    char string1[21]="The wheel of fortune";
    char string2[21]="The wheel of fortune";
    printf("原始字符串是: %s\n",string1);
    for(int i=0;i<21;++i)
        {
           if(islower(string2[i]))
           {
               string2[i]=toupper(string2[i]);
           }
        }
    printf("变化后的字符串是: %s\n",string2);
}

void lower()
{
    char string1[21]="The wheel of fortune";
    char string2[21]="The wheel of fortune";
    printf("初始字符串是: %s\n",string1);
    for(int i=0;i<21;++i)
        {
            if(isupper(string2[i]))
            {
                string2[i]=tolower(string2[i]);
            }
        }
    printf("变化后的字符串是: %s\n",string2);
}
void comparison()
{
    char string1[21]="The wheel of fortune",string2[21]="Temperance";
    printf("第一个字符串是: %s\n""第二个字符串是: %s\n",string1,string2);
    if(string1<string2)
    {
        puts("第一个小于第二个");
    }
    else if(string1>string2)
    {
        puts("第一个大于第二个");
    }
    else
    {
        puts("两个字符串相等");
    }
}
void calculation()
{
    char choice;
    int number1,number2;
    printf("请先分别输入两个整数: \n");
    scanf("%d%d",&number1,&number2);
    printf("+:加\n""-:减\n""*:乘\n""/:除\n");
    printf("请输入你的选择的运算符：");
      scanf("%s",&choice);
        switch(choice)
        {
        case'+':
        printf("计算的结果是：%d\n",number1+number2);
        break;
        case'-':
        printf("计算的结果是：%d\n",number1-number2);
        break;
        case'*':
        printf("计算的结果是：%d\n",number1*number2);
        break;
        case'/':
        printf("计算的结果是：%d\n",number1/number2);
        break;
        default:
        puts("错误!");
        break;
        }
}
