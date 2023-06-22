#include <stdio.h>

#define SIZE 100
#define TO_LOWER_(c) (((c) >= 'A' && (c) <= 'Z') ? (c) + ('a'-'A') : c)
#define TO_UPPER_(c) (((c) >= 'a' && (c) <= 'z') ? (c) - ('a'-'A') : c)

int asci_to_int (char *str);
char to_lower_char (char c);
char to_upper_char (char c);
void string_to_upper (char *str);
void string_to_lower (char *str);
void string_copy (char *dis, char *source);
void mem_copy(char *dis, char *src, int size);
void display_mem(char *str, int arr_size);
char *str_cat(char *str1, char *str2);
void swap(char c1,char c2);

/* Main Function */
int main()
{
	char array[SIZE], result[SIZE];
	int i=123, size;
	char ch = 's', str[20] = "Karthik";
	char *cptr = &ch;
	
	printf("Enter the first string :\n");
	gets(array);
	
	//int result = asci_to_int(array);
	//printf("Number is:%d",result);
	//printf("when input is pointer,to lower: %c\n",to_lower_char(*cptr));
	//printf("when input is pointer,to upper: %c\n",to_upper_char(*cptr));
	//printf("when input is pointer, to upper using macro: %c\n",TO_UPPER_(*cptr));
	//printf("when input is pointer,to lower using macro: %c\n",TO_LOWER_(*cptr));
	
	//printf("when input is address to pointer,to lower: %c\n",to_lower(cptr));
	//printf("when input is address to pointer,to upper: %c\n",to_upper(cptr));
	//printf("when input is address to pointer,to upper using macro: %c\n",TO_UPPER_(cptr));
	//printf("when input is address to pointer,to lower using macro: %c\n",TO_LOWER_(cptr));
	
	/*string_to_upper(array);
	printf("Converted string:%s\n",array);
	
	string_to_lower(array);
	printf("Converted string:%s\n",array);
	
	string_copy(result, array);
	//printf("Copied string is: %s\n",result);
	
	//printf("Enter size:\n");
	//scanf("%d",&size); */
	mem_copy(result, str, size);
	//printf("Memory copied:%s\n", result);
	
	//display_mem(array, size);
	/*char *ptr1 = str_cat(array,str);
	
	printf("Concatenated string is:%s\n", ptr1);
	
	return 0;
	
	char c = 'K';
        mem_set(array, c, sizeof(array));*/
        
        string_reverse(array);
}


/* Function to set aside the memory */
void mem_set(char *ptr,char c, int size)
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
	for (i;str[i] != '\0';i++)
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
	for(i; i< arr_size; i++)
	{
		if((i%7) == 0)
			printf("0x");
		printf("%x ",(str[i] & 0xff));
		if((i%7) == 6)
			printf("\n");
	}
	printf("\n");
}

/* Function for string concatenation */
char *str_cat(char *str1, char *str2)
{
	char *str = str1;
	
	printf("str1:%s str2:%s\n", str1, str2);
	
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


