#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,i,j,k;//��������

    num=100;//����ֵ

    printf("All of the Narcissus few is: ");//��ʾ�û��������ʲô

    while(num<=999)//�ж�
    {
        i=num/100;
        j=(num-i*100)/10;
        k=num%10;

        if(num==i*i*i+j*j*j+k*k*k)
        {
            printf("%d  ",num);//���ˮ�ɻ���
        }
        num=num+1;
    }

    return 0;
}
