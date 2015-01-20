# include <cs50.h>
# include <stdio.h>
# include <math.h>

int main(void)
{
float change;
    do
    {
        printf("O hai!  How much change is owed?\n");
        change = GetFloat(); // get amount from user
    }    
    while (change<0);
    
    //initiate variables
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    change = round(change*100); //convert into total cents
    //use loops to count multiples of each denomination
    while (change >= 25)
        {
        change = change - 25;
        quarters++;
        }
    while (change >= 10)
        {
        change = change - 10;
        dimes++;
        }
    while (change >= 5)
        {
        change = change - 5;
        nickels++;
        }
    while (change >= 1)
        {
        change = change - 1;
        pennies++;
        }
        
    printf("%i\n",(quarters + dimes + nickels + pennies));   
}
