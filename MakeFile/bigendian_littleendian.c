
/* Program to find if the system is BIG ENDIAN or LITTLE ENDIAN  */
/* Program to find if substring is present or not */
#include <stdio.h>
//#include "utility.h"

#define BIG_E 1
#define LITTLE_E 0

#define IS_BIG_END ((get_endian() == BIG_E) ? 1 : 0)

int get_endian();

/* Main Function */
int big_little_endian_main()
{
    get_endian();
    if(IS_BIG_END)
        printf("\n Big Endian \n");
    else
        printf("\n Little Endian \n");
     
    /*    
    char s1[] = "EMinds India";
    char s2[] = "EMinds";    
    int cmp;
    cmp = str_cmp(s1,s2);
    if(cmp == 0)
        printf("\n Same Strings \n %s", s2);
    else if(cmp < 0)
        printf("\n Second string is too long \n");
    else
        printf("\n Strings Not Matching \n");
    
    
    int subs;
    subs = str_substr(s1,s2);
    if(subs == 1)
        printf("\n Substring Present \n");
    else
        printf("\n Substring Not Present \n");
    
    */
    return 0;  
}

/* CHECKING get_endian FUNCTION */
int get_endian()
{
    int int_val = 0x1A2B3C4D;
    char *c_ptr = (char *) &int_val;
    printf("\n %x \n", c_ptr);
    
    if(c_ptr[0] == 0x1A)
        return BIG_E;
    else
        return LITTLE_E;
}

/* Function to check if bothe the strings are same or not 
int str_cmp(char *s1, char *s2)
{
    while(*s1++ == *s2++)
        if(*s1 == '\0')
            return 0;
    return (*s1 - *s2);
} 

/* Function to check if substring exists or not 
int str_substr(char *s1,char *s2)
{
    int index, match;
    index = match = 0;
    while(*s2 != '\0')
    {
        if(*s1 == *s2)
        {
            s1++;
            s2++;
        }
        else
            s1++;
    }
    if(*s1 == *s2--)
        match = 1;
    
    if(match == 1)
        return 1;
    else
        return 0;
}
*/

#ifndef RELOCATABLE_OBJ
int main()
{
    big_little_endian_main();
}
#endif  /* Ended DRELOCATE */  




