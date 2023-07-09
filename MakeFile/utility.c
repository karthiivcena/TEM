#include "utility.h"

/* Utilitie Main Function */
int utility_main()
{
	char array[SIZE], result[SIZE];
	int size;
	printf("Enter the first string :\n");
	scanf("%s",array);
	char ch = 's', str[20] = "Sanjay";
	
	char *cptr;
	cptr = &ch;
	
	char arr[] = "123456";
	int result1 = asci_to_int(arr);
	
	  
	
	printf("\n Number is : %d \n",result1);
	
	printf("\n When input is pointer,to lower : %c \n",to_lower_char(*cptr));
	printf("\n When input is pointer,to upper: %c \n",to_upper_char(*cptr));
	printf("\n When input is pointer, to upper using macro : %c \n",TO_UPPER_(*cptr));
	printf("\n When input is pointer,to lower using macro: %c \n",TO_LOWER_(*cptr));
	
	printf("\n When input is address to pointer,to lower: %c \n",to_lower_char(*cptr));
	printf("\n When input is address to pointer,to upper: %c \n",to_upper_char(*cptr));
	printf("\n When input is address to pointer,to upper using macro: %c \n",TO_UPPER_(*cptr));
	printf("\n When input is address to pointer,to lower using macro: %c \n",TO_LOWER_(*cptr));
	
	string_to_upper(array); 
	printf("\n Converted string to UPPER : %s \n",array);
	
	string_to_lower(array);
	printf("\n Converted string to LOWER : %s \n",array);
	
	string_copy(result, array);
	printf("\n Copied string is : %s \n",result);
	
	printf("\n Enter size for copying memory : \n");
	scanf("%d",&size); 
	mem_copy(result, str, size);
	printf("\n Memory copied : %s \n", result);
	
	display_mem(array, size);
	char *ptr1 = str_cat(array,str);
	
	printf("\n Concatenated string is : %s \n", ptr1);
	
	string_reverse(array);
	
	char c = 'K';
        mem_sets(array, c, sizeof(array));
        
	char s1[] = "EMinds India";
        char s2[] = "EMinds India"; 
	
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
    
        
        return 0;
}

/* Function to check if bothe the strings are same or not */
int str_cmp(char *s1, char *s2)
{
    while(*s1++ == *s2++)
        if(*s2 == '\0')
            return 0;
    return (*s1 - *s2);
}

/* Function to set aside the memory */
void mem_sets(char *ptr,char c, int size)
{
    int index = 0;
    while(index < size)
    {
        *(ptr + index) = c;
        index += 1;
    }  
}

/* Function to Reverse a String */
void string_reverse(char str[SIZE])
{
    if(str == NULL)
    {
        printf(" \n Passing NULL as Parameter \n");
        exit(0);
    }
    int index1,index2, str_len = 0;
    for(index1 = 0; str[index1] != '\0'; index1++)
        str_len += 1;
    for(index1 = 0,index2 = str_len - 1; index1 < index2; index1++, index2--)
    {
        char temp = *(str + index1);
        *(str + index1) = *(str + index2);
        *(str + index2) = temp;
    }
    printf(" Reversed string is : %s \n ", str);
}

// Function to convert numbers given in string to decimal number
int asci_to_int (char *str)
{
	int i=0, number=0, sign=1;
	int sign_present=0, digit_started=0;
	for (;str[i] != '\0';i++)
	{
		if (str[i] == '+' || str[i] =='-')
		{
			if(sign_present == 1)
			{
				printf("Error: invalid input at index: %d with %c",i, str[i]);	// checking symbols in between digits
				break;
			}
			if (digit_started == 1)
			{
				printf("Error: invalid input at index: %d with %c",i, str[i]);	// checking digit started or not
				break;
			}
			sign_present = 1;
			if(str[i] == '-')
			{
				sign = -1;
			}
		}
		else if (str[i] == ' ' || str[i] =='\n')
		{
			printf("Error: invalid input at index: %d with %c",i, str[i]);		// checking for spaces in between digits
			break;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			digit_started = 1;
			number = number * 10 + (str[i] - '0');					// converting to decimal number
		}
		else
		{
			printf("Error: unexpected error");
			break;
		}
		
	}
	if (str[0] == '+')
		return number;									// checking for +ve and -ve numbers
	else
		return sign*number;
}

/* Functiont to convert a character to lower case */
char to_lower_char(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c= c + ('a'-'A');
	}
	return c;
}

/* Functiont to convert a character to upper case */
char to_upper_char(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c= c - ('a'-'A');
	}
	return c;
}

/* Functiont to convert a string to upper case */
void string_to_upper (char *str)
{
	while (*str !='\0')
	{
		*str = to_upper_char(*str);
		str++;
	}
	*str = '\0';
}

/* Functiont to convert a string to lower case */
void string_to_lower (char *str)
{
	while (*str !='\0')
	{
		*str = to_lower_char(*str);
		str++;
	}
	*str = '\0';
}

/* Funtion to copy the string from source file to destination file */ 
void string_copy (char *dis, char *source)
{
	int i=0;
	while (source[i] != '\0')
	{
		dis[i] = source[i];
		i++;
	}
}

/* Function to copy memory of one type from source to destination */
void mem_copy(char *dis, char *src, int size)
{
	int i=0;
	while (i <= size)
	{
		*(dis + i) = *(src + i);
		i++;
	}
}

/* function to display the memory size */
void display_mem (char *str,int arr_size)
{
	int i=0;
	if (!str)
		return;
	for(; i < arr_size; i++)
	{
		if((i%7) == 0)
			printf("0x");
		printf(" %x ",(str[i] & 0xff));
		if((i%7) == 6)
			printf("\n");
	}
	printf("\n");
}

/* Function for string concatenation */
char *str_cat(char *str1, char *str2)
{
	char *str = str1;
	
	printf("\n Str1 : %s \n Str2 : %s \n", str1, str2);
	
	if(!str1)
		return NULL;
	if(!str2)
		return str1;
	
	while (*str1 != '\0')
		str1++;

	while (*str2 !='\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return str;
}

/* Function to check if substring exists or not */
int str_substr(char *s1,char *s2)
{
  if (*s2 == '\0')
        return 1;                                        // Empty substring is always present

    while (*s1 != '\0') {
        if (*s1 == *s2) {
            const char *s = s1;
            const char *sub = s2;
            while (*s != '\0' && *sub != '\0' && *s == *sub) {
                s++;
                sub++;
            }
            if (*sub == '\0')
                return 1;                                // Substring found
        }
        s1++;
    }
    
    return 0; // Substring not found
}

#ifndef RELOCATABLE_OBJ
int main()
{
    utility_main();
}
#endif   /* Ending the Relocatable */

