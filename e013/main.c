#include <stdio.h>
#include <stdlib.h>

float OriginalPrice;
float DiscountRate;
float NewPrice;

void Welcome_Message();
float Input_Data();
float Compute_Results(float OriginalPrice,float DiscountRate);
float Output_Results(float OriginalPrice,float DiscountRate,float NewPrice);

int main()
{
    Welcome_Message();
    Input_Data();
    NewPrice = Compute_Results(OriginalPrice,DiscountRate);
    Output_Results(OriginalPrice,DiscountRate,NewPrice);
}

void Welcome_Message()
{
    printf("Welcome to Sale Price Program\n");
    printf("This program computes the saleprice of\n");
    printf("an item that has been discounted a certain percentage.\n");
}

float Input_Data()
{
    printf("What is its price: ");
    scanf("%f",&OriginalPrice);
    printf("What is the percentage discounted?\n");
    scanf("%f",&DiscountRate);
    return OriginalPrice,DiscountRate;
}

float Compute_Results(float OriginalPrice,float DiscountRate)
{
    float Amount_saved;
    float NewPrice;
    Amount_saved = OriginalPrice*(DiscountRate/100);
    NewPrice = OriginalPrice-Amount_saved;
    return NewPrice;
}

float Output_Results(float OriginalPrice,float DiscountRate,float NewPrice)
{
    printf("Pre-sale Price was: %f$\n",OriginalPrice);
    printf("Percentage discounted was: %f%%\n",DiscountRate);
    printf("Sale price: %f$\n",NewPrice);
}
