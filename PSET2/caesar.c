#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    
    if ((argv[1] < 0) || (!argv[1]) || argc!= 2)
    {
        printf("You must only enter one number at the command line!\n");
        return 1;  
    }
  
    int k = atoi(argv[1]);
    string user_text = GetString();

    for (int i = 0, n = strlen(user_text); i < n; i++)
    {
        if (isalpha(user_text[i]))
        {
            if (islower(user_text[i]))
            {
                int x = user_text[i];
                x = (x - 'a' + k) % 26 + 'a';
                user_text[i] = (char) x;
            }
            if (isupper(user_text[i]))
            {
                int x = user_text[i];
                x = (x - 'A' + k) % 26 + 'A';
                user_text[i] = (char) x;
            }       
        }
        printf("%c", user_text[i]);
    }
    printf("\n");
    return 0;

}
