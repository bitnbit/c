#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Score,Count,Number,Amount;//�������
    Amount=10;//����ֵ
    Number=0;

    printf("Please input ten students�� test scores.\n");//��ʾ�û��������ݵ�����

    for(Count=1;Count<=Amount;Count++)//�ж��Ƿ��Ѿ�����ʮ������
    {
        printf("Please input student's score: ");//��ʾ�û�����
        scanf("%d",&Score);
        if(Score>=60)//�ж��Ƿ񼰸�
        {
            Number=Number+1;
        }
    }

    printf("The number of passing students is: ""%d\n",Number);//������

    return 0;
}
