#include <stdio.h> 

int value = 5;
int values[] = {2,4,5,12,23,34};
int n = 6;

int re_search(int value, int values[], int n);
 
int main(void)
{

    re_search(value, values, n);
    return 0;

} 

int re_search(int value, int values[], int n)
{
    int first = 0;
    int last = n-1;
    int middle = (first+last)/2;
     
    while (first <= last)
    {
        if (value == values[middle])
        {
            printf("You found it!\n");
            return 0;
        }
        else if (value > values[middle])
        {
          first = middle + 1;
          middle = (first + last) / 2;
          return re_search(value, &values[middle], last-first);
        }    
        else
        {
            last = middle - 1;
            return re_search(value, &values[middle], last-first);
        }    
        middle = (first + last) / 2;
             
    }
    printf("Did not find it!\n");
    return 0;
}
