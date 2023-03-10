#include <stdio.h>
#include <stdlib.h>

float Average_Compute(float ScoreSum,float ClassCount);

int main()
{
    float Score;
    int Count;
    float Sum;
    float Average;
    Sum = 0;
    Count = 1;
    while(Count<=5)
    {
        printf("Enter one exam grade: ");
        scanf("%f",&Score);
        Sum = Sum + Score;
        Count =Count + 1;
    }
    Average = Average_Compute(Sum,Count-1);
    printf("Exam average is: %f",Average);
}

float Average_Compute(float ScoreSum,float ClassCount)
{
    return ScoreSum/ClassCount;
}
