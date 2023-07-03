//Program to Set the Bit Number to 1 and Clear it to 0
//Macros are defined in the file set_clear.h


#include <stdio.h>
#include "set_clear.h"

int set = 0;
int cl = 0;
int b = 0;
int d = 0;
int a = 99;

int main()
{
    int position = 3;
    int s = set_number(a, position);
    printf("\n Before setting: %d \n After setting,New Value: %d \n Hexadecimal: %x \n ", a, s, s);
    int c = clear_bit(a,position);
    printf("\n Before Clearing: %d \n After clearing, New Value: %d \n Hexadecimal: %x \n ", a, c, c);
}

//SETTING A BIT TO 1
int set_number(int a, int position)
{
    set = (a | (1 << position));
    bin(a);    
    return set;
}


//CLEARING A BIT...SETTING A BIT TO 0
int clear_bit(int a, int position)
{
    cl = (set & (~ (1 << position)));
    bin( a );
    return cl;
}

//BINARY CODE
void bin(int no)
{
    int temp = no;
    int i = 0;
    char binary_str[32] = { 0 };
    for ( i=31; i >= 0; i--)
    {
        if(no & 0x01)
            binary_str[i] = '1';
	else
	    binary_str[i] = '0';
	no = no >> 1;
    }
    binary_str[32] = '\0';
    printf("\n No %d = %s \n", temp, binary_str);
}


