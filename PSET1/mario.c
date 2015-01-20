#include <cs50.h>
#include <stdio.h>

// create a pyramid based on user input on height

int main(void)
{
    printf("Height: ");
    int height = GetInt(); // get height from user
    if (height == 0)
        {
            return 0;
        }    
    
    while (height < 0 || height > 23) // if out of bounds, keep asking
        {
             printf("Height: ");
             height = GetInt();
        }
    
    int counter = 0;
    while (counter < height) //produce pyramid
    {    
        for (int i=0; i < (height-counter-1); i++) //produce left space
            {
                printf(" ");
            }
        for (int i=0; i < (counter+1); i++) //produce left side hash
            {       
                printf("#");
            }    
        
        printf("  "); //produce middle space
            
        for (int i=0; i < (counter+1); i++) //produce right side hash
            {       
                printf("#");
            }
/*        for (int i=0; i < (height-counter-1); i++) //produce right space*/
/*            {*/
/*                printf(" ");*/
/*            }        */
    printf("\n"); //print new line
    counter++;
    }
    return 0;
}
