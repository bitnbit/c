#include <stdio.h>
#include <stdlib.h>
#define NUMBER 5

int main()
{
    int score[NUMBER]={82,66,73,58,92};
    puts("The scores in original order are: ");
    for(int i=0;i<NUMBER;++i)
    {
        printf("%d  ",score[i]);
    }
    puts("");
    for(int i=0;i<NUMBER;++i)
    {
        for(int j=0;j<NUMBER-i-1;++j)
        {
            if(score[j]<score[j+1])
            {
                int temp;
                temp=score[j];
                score[j]=score[j+1];
                score[j+1]=temp;
            }
        }
    }
    puts("The scores in descending order are: ");
    for(int i=0;i<NUMBER;++i)
    {
        printf("%d  ",score[i]);
    }
}
