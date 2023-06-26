/* Program to find if the system is BIG ENDIAN or LITTLE ENDIAN  */
/* Program to find if substring is present or not */

#include <stdio.h>

#define BIG_ENDIAN 1
#define LITTLE_ENDIAN 0;
#define IS_BIG_ENDIAN (get_endian() == BIG_ENDIAN) 
#define IS_LITTLE_ENDIAN (get_endian() == LITTLE_ENDIAN)

int get_endian();
int str_cmp(char *s1, char *s2);
int str_substr(char *s1,char *s2);

/* Main Function */
int main()
{
    get_endian();
    if(IS_BIG_ENDIAN)
        printf("\n Big Endian \n");
    else
        printf("\n Little Endian \n");
        
    char s1[] = "EMinds India";
    char s2[] = "EMioia";    
    int cmp;
    cmp = str_cmp(s1,s2);
    if(cmp == 0)
        printf("\n Same Strings \n %s", s2);
    else if(cmp < 0)
        printf("\n Substring is too long \n");
    else
        printf("\n Substring not found \n");
    
    int subs;
    subs = str_substr(s1,s2);
    if(subs == 1)
        printf("\n Substring Present \n");
    else
        printf("\n Substring Not Present \n");
    
    return 0;  
}

/* CHECKING get_endian FUNCTION */
int get_endian()
{
    int int_val = 0x1A2B3C4D;
    char *c_ptr = (char *) &int_val;
    printf("\n %x \n", c_ptr);
    
    if(c_ptr[0] == 0x1A)
        return BIG_ENDIAN;
    else
        return LITTLE_ENDIAN;
}

/* Function to check if bothe the strings are same or not */
int str_cmp(char *s1, char *s2)
{
    while(*s1++ == *s2++)
        if(*s1 == '\0')
            return 0;
    return (*s1 - *s2);
}

/* Function to check if substring exists or not */
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
    
    





