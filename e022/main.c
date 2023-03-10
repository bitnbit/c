#include <stdio.h>
#include <stdlib.h>

#define NUMBER 5

int main()
{
    int score[NUMBER],max=0,k;
    for(int i=0;i<NUMBER;++i)
    {
        printf("Please input the score of student %d: ",i+1);
        scanf("%d",&score[i]);
        if(score[i]>max)
        {
            max=score[i];
            k=i+1;
        }
    }
    printf("The student with the highest score is student %d, "
           "and the highest score is %d.\n",k,max);
}
