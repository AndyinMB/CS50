#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    printf("Give me a number: \n");
    double cardnumber = GetLongLong();
    if(cardnumber < 1000000000000 || cardnumber > 10000000000000000)
    {
        printf("INVALID\n");
        return 0;
    }
    if(cardnumber < 100000000000000 && cardnumber > 9999999999999)
    {
        printf("INVALID\n");
        return 0;   
    }
    
    char creditcard[17];
    sprintf(creditcard, "%f", cardnumber);
    char* ptr_cc;
    ptr_cc = strtok(creditcard,".");
    int card_size = strlen(ptr_cc);
    int sum = 0;
    for(int i = 1; i < card_size; i+=2)
    {
        int x = creditcard[card_size-1-i] - '0';
        int prod = 2 * x;
        if(prod>=10)
        {
            prod = prod%10 + prod/prod%10;
        }
        sum += prod;      
    }
    for(int i = 0; i < card_size; i+=2)
    {
        int x = creditcard[card_size-1-i] - '0';
        sum += x;      
    }
    if(sum%10 != 0)
    {
        printf("INVALID\n");
        return 0; 
    }
    else if(creditcard[0] == '4')
    {
        printf("VISA\n");
        return 0; 
    }
    else if(creditcard[0] == '3' && (creditcard[1] == '7' || creditcard[1] =='4'))
    {
        printf("AMEX\n");
        return 0; 
    }
    else if(creditcard[0] == '5' && (creditcard[1] >='1' && creditcard[1] <='5'))
    {
        printf("MASTERCARD\n");
        return 0; 
    }
    else
    {
        printf("INVALID\n");
        return 0;    
    }         
}
