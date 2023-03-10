#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define SUITS 4
#define FACES 13
#define CARDS 52
void shuffle(unsigned int wdeck[][FACES]);
void deal(unsigned int wdeck[][FACES],const char *wface[],const char *wsuit[]);
int main(void)
{
    unsigned int deck[SUITS][FACES]={0};
    srand(time(NULL));
    shuffle(deck);
    const char *suit[SUITS]={"Hearts","Diamonds","Clubs","Spades"};
    const char *face[FACES]={"Ace","Deuce","Three","Four","Five","Six","Seven",
    "Eight","Nine","Ten","Jack","Queen","King"};
    deal(deck,face,suit);
}
void shuffle(unsigned int wdeck[][FACES])
{
    for(size_t card=1;card<=CARDS;++card)
    {
    size_t row,column;
    do
    {
    row=rand()%SUITS;
    column=rand()%FACES;
    }
    while(wdeck[row][column]!=0);
    wdeck[row][column]=card;
    }
}
void deal(unsigned int wdeck[][FACES],const char *wface[],const char *wsuit[])
{
    for(size_t card=1;card<=CARDS;++card)
    {
    for(size_t row=0;row<SUITS;++row)
    {
    for(size_t column=0;column<FACES;++column)
    {
    if(wdeck[row][column]==card)
    {
    printf("%5s of %-8s%c",wface[column],wsuit[row],card%2==0?'\n':'\t');
    }
    }
    }
    }
}
