#include <stdio.h>
#include <crypt.h>
#include <unistd.h>
#include <string.h>

#define _XOPEN_SOURCE

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack <password>\n");
        return 1;
    }
    
    int n = strlen(argv[1]);
    char password[n];
    
    for (int i = 0; i < n; i++)
    {
        password[i] = argv[1][i];
    }
    
    char salt[2]; 
    salt[0] = password[0];
    salt[1] = password[1]; 
    printf("%s\n", salt);
    printf("%s\n", argv[1]);
    printf("%s\n", crypt("crimson", salt));

    if (!strcmp(argv[1], crypt("crimson", salt)))
    {
        printf("Hacked!\n");
    }
    else
    {
        printf("Try Again\n");
    }
    return 0;
}
