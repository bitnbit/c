#include <stdio.h>
#include <stdlib.h>
#define NUMBER 5

int search(int score[],int low,int high,int s);

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
    puts("");
    int index,s;
    printf("Please enter the score you want to search: ");
    scanf("%d",&s);
    index=search(score,0,NUMBER,s);
    if(index==-1)
    {
        printf("The score is not found.");
    }
    else
    {
        printf("The place of the score is %d.",index+1);
    }
}

int search(int score[],int low,int high,int s)
{
    int mid=(low+high)/2;
    if(low<=high)
    {
        if(s==score[mid])
        {
            return mid;
        }
        else if(s<score[mid])
        {
            return search(score,mid+1,high,s);
        }
        else
        {
            return search(score,low,mid-1,s);
        }
    }
    else
    {
        return -1;
    }
}
