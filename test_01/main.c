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
    printf("1: �����ַ�\n"
           "2: ���ַ�ȫ��ת��Ϊ��д\n"
           "3: ���ַ�ȫ��ת��ΪСд\n"
           "4: �������ַ����д�С�Ƚ�\n"
           "5: ���м���������\n");
    printf("���������ѡ��: ");
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
    else{puts("����!");};
    }

void copy()
{
    char string1[21]="The wheel of fortune";
    char * string2[21];
    printf("ԭʼ�ַ�����: %s\n",string1);
    string2[0]=&string1;
    printf("���ƶ������ַ�����: %s\n",*string2);
}

void upper()
{
    char string1[21]="The wheel of fortune";
    char string2[21]="The wheel of fortune";
    printf("ԭʼ�ַ�����: %s\n",string1);
    for(int i=0;i<21;++i)
        {
           if(islower(string2[i]))
           {
               string2[i]=toupper(string2[i]);
           }
        }
    printf("�仯����ַ�����: %s\n",string2);
}

void lower()
{
    char string1[21]="The wheel of fortune";
    char string2[21]="The wheel of fortune";
    printf("��ʼ�ַ�����: %s\n",string1);
    for(int i=0;i<21;++i)
        {
            if(isupper(string2[i]))
            {
                string2[i]=tolower(string2[i]);
            }
        }
    printf("�仯����ַ�����: %s\n",string2);
}
void comparison()
{
    char string1[21]="The wheel of fortune",string2[21]="Temperance";
    printf("��һ���ַ�����: %s\n""�ڶ����ַ�����: %s\n",string1,string2);
    if(string1<string2)
    {
        puts("��һ��С�ڵڶ���");
    }
    else if(string1>string2)
    {
        puts("��һ�����ڵڶ���");
    }
    else
    {
        puts("�����ַ������");
    }
}
void calculation()
{
    char choice;
    int number1,number2;
    printf("���ȷֱ�������������: \n");
    scanf("%d%d",&number1,&number2);
    printf("+:��\n""-:��\n""*:��\n""/:��\n");
    printf("���������ѡ����������");
      scanf("%s",&choice);
        switch(choice)
        {
        case'+':
        printf("����Ľ���ǣ�%d\n",number1+number2);
        break;
        case'-':
        printf("����Ľ���ǣ�%d\n",number1-number2);
        break;
        case'*':
        printf("����Ľ���ǣ�%d\n",number1*number2);
        break;
        case'/':
        printf("����Ľ���ǣ�%d\n",number1/number2);
        break;
        default:
        puts("����!");
        break;
        }
}
