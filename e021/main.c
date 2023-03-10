#include <stdio.h>
#include <stdlib.h>

#define NUMBER 5

int main()
{
    int Score[NUMBER]={82,66,73,58,92};
    float sum=0,ave=0;
    puts("The scores are: ");
    for(int i=0;i<NUMBER;++i)
    {
        printf("%4d",Score[i]);
        sum=sum+Score[i];
    }
    puts("");
    ave=(sum/NUMBER);
    printf("The sum of the scores is %.2f\n",sum);
    printf("The average of the scores is %.2f\n",ave);
}
