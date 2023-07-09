/* Program to Sort the array and search for an element in the array using Binary Search */

extern "C"
{
#include <stdio.h>
#include <cstring>
#define SIZE 15
#define TRUE 1
#define FALSE 0
#define IS_CHAR(s) (s == ' ' || s == '\t' || s == '\n') ? 0 : 1
#define IS_SPACE(c) (c=='\n') || (c== ' ') || (c=='\t') ? 1 : 0

int sort (int array[], int length);
int binary_search (int array[], int length, int key);
void swap (int *aptr, int *bptr);
char *trim(char *str);
int is_char(char s);


/* Main Function */
int sort_bin_main()
{
    int array[SIZE], i, j, temp, key, indx, flag;
    flag = TRUE;
    char *str_ptr;
    indx = 0;
    char str[SIZE],c;
    printf("\n Enter the string : \n");
    for(i = 0;((c=getchar()) != EOF) && (i < SIZE) ; i++)
    {
        str[i] = c;
    }
    str[i] = '\0';
    
    
    str_ptr = trim(str);
    printf("\n Trimmed String is :"); 
    for(; *(str_ptr+indx) != '\0';indx++)
    {
        printf("%c", *(str_ptr+indx));
    }
    i = 0;
    while(flag)
    {
	printf("\n Enter the number : \n");
	scanf("%d", &temp);
	if (temp == 100)
	{
	    flag = FALSE;
	}
	else
	{
	    array[i] = temp;
	    i++;
	}
    }
    
    printf("\n Sorted array : \n");
    sort (array, i);
    for (j=0; j <i; j++)
    {
	printf("%d, ",array[j]);
    }
    
    printf("\n Enter the key value : \n");
    scanf("%d", &key);
    int position;
    position = binary_search(array, i, key);
    if (position == -1)
    {
 	printf("\n Element not found in the array \n ");
    }
    else
    {
	printf("\n Element found at index : %d \n", position);
    }
    return 0;
}

/* Trim Function */
char *trim(char *str)
{
    int len = strlen(str);
    int start = 0, end = len - 1;

    // Trim leading whitespace
    while (IS_SPACE(str[start]))
        start++;

    // Trim trailing whitespace
    while ((end >= start) && (IS_SPACE(str[end])))
        end--;

    // Shift characters to the beginning of the array
    int i, j;
    for (i = 0, j = start; j <= end; i++, j++)
        str[i] = str[j];

    /* Null-terminate the trimmed string */
    str[i] = '\0';

    return str;
}

/* Function to check if the index of the string is a space or not */
int is_char(char s)
{
    if(s == ' ' || s == '\t' || s == '\n')
        return 0;
    else
        return 1;
}

/* Swap Function */
void swap (int *ptr1, int *ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

/* Sort Function */
int sort (int array[], int length)
{
    int index1, index2;
    for (index1 = 0; index1 < length; index1++)
    {
	for (index2 = index1; index2 < length; index2++)
	{
       	    if (array[index1] > array[index2])
		swap(&array[index1], &array[index2]);
	}
    }
}

/* Binary Search Function */
int binary_search (int array[], int length, int key)
{
    
    int low = 0, mid, high = length - 1;
    while (low <= high)
    {
	mid = (low + high)/2;
			
	if (array[ mid ] == key)
	    return mid;
	else if (array[ mid ] < key)
   	    low = mid + 1;	
	else 
       	    high = mid -1;	
    }
    return -1;
}


#ifndef RELOCATABLE_OBJ
int main()
{
    sort_bin_main();
}
#endif  /* Ended DRELOCATE */	
}

