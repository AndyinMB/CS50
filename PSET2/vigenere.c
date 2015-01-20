#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int key(char letter)  //function returns numerical value of each character in key
{
    int x = letter;
    if (islower(letter))
    {
        x = (x - 'a') % 26;
    }
  
    if (isupper(letter))
    {
      x = (x - 'A') % 26;
    }
    return x;
}

int main (int argc, string argv[])
{
    
    if ((argv[1] < 0) || (!argv[1]) || argc!= 2) //check for only one additional command line argument
    {
        printf("You must only enter one key (a string) at the command line!\n");
        return 1;  
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++) //reject keyword if not all alpha chars
    {
        if (!(isalpha((argv[1][i]))))
        {
            printf("Key must only contain alphabetical characters!\n");
            return 1;
        } 
    }
  
    string user_text = GetString();

    for (int i = 0, j = 0, n = strlen(user_text); i < n; i++)
    {
        if (isalpha(user_text[i])) //this ensures that only letters are enciphered
        {
            if (islower(user_text[i]))
            {
                int x = user_text[i];
                int k = key(argv[1][j % strlen(argv[1])]); //adjust for key length < string length
                x = (x - 'a' + k) % 26 + 'a'; //convert from ascii value to 0, add key, back to ascii value
                user_text[i] = (char) x;
            }
            if (isupper(user_text[i])) //same as above but for upper case charcaters in string
            {
                int x = user_text[i];
                int k = key(argv[1][j % strlen(argv[1])]);
                x = (x - 'A' + k) % 26 + 'A';
                user_text[i] = (char) x;
            }       
        j++; //only increment key index for characters
        }
        printf("%c", user_text[i]);
    }
    printf("\n");
    return 0;

}
