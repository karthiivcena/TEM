/*Program to convert character string to integer*/

#include <stdio.h>

#define SIZE 120
#define POSITIVE {'+1'}
#define NEGATIVE {'-1'}
#define START 1
#define NOT_START 0
#define PRESENT 1
#define NOT_PRESENT 0

int ascii_to_int(char *str);

int main()
{
    int i;
    char str[SIZE];
    printf("\n Enter the string of size %d \n", SIZE);
    scanf("%[^\n]",str);
    int int_val =  ascii_to_int(str);
    printf("\n The integer value is : %d \n ", int_val);
    return 0;
}

/* charater string to integer conversion */
int ascii_to_int(char *str)
{   
    int digit = 0;
    int sign = 1;
    int sign_started = 0;
    int digit_started = 0;
    int number = 0;
    int i = 0;
    for(i;str[i] != '\0'; i++)
    {
        if(str[i] == '-' || str[i] == '+')
	{
	    if(digit_started == PRESENT)
	    {
	        printf(" Error : Digit already present \n");
	        return 0;
	    }
	    if(sign_started == 1)
	    {
	        printf("Error : Invalid input of the sign \n");
	        return 0;
	    }
	    sign_started = 1;
	    if(str[i] == '-')
	    {
	        sign = -1;
	    }
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {   
    	    digit_started = PRESENT;
            number = number * 10 +(str[i] - '0');
        }   
        else
        {
            printf("\n Error : Digits not present \n");
            return 0;
        }
    }
    if(str[0] == '+')
        return number;
    else
        return (sign*number);
}


