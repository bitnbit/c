#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Number1,Number2,MaxValue;//�������

    printf("Please input two numbers: ");//��ʾ�û���������
    scanf("%d%d",&Number1,&Number2);

    if (Number1 == Number2)//�ж�
    {
        printf("The numbers are the same.\n");//������
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
        printf("The numbers are: ""%d,%d\n",Number1,Number2);//������
        printf("The larger number is: ""%d\n",MaxValue);

    }
    return 0;
}
