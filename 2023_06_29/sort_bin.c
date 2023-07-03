#include <stdio.h>
#define SIZE 100
#define IS_CHAR(s) (s == ' ' || s == '\t' || s == '\n') ? 0 : 1

int sort (int array[], int length);
int binary_search (int array[], int length, int key);
void swap (int *aptr, int *bptr);
char *trim(char *str);
int is_char(char s);

/* Main Function */
int bin_sort_main()
{
    int array[SIZE], i=0, j, temp, key, indx;
    indx = 0;
    char str[SIZE];
    printf("\n Enter the string : \n");
    scanf("%[^\n]",str);
    char *str_ptr;
    str_ptr = trim(str);
    printf("\n Trimmed String is : "); 
    for(indx; *(str_ptr+indx) != '\0';indx++)
    {
        printf("%c", str[indx]);
    }
    
    while (1)
    {
	printf("\n Enter the number:\n");
	    scanf("%d", &temp);
	if (temp == 100)
	    break;
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
    int index, j, k, in, spce;
    index = spce = j = k = 0;
    int last_char;
    last_char = 0;
    
    if(!str)
        return NULL;
      
    while(str[j] != '\0')
    {
        if(!IS_CHAR(str[j]))
            spce++;
        j++;
    }
               
    if(spce != 0)
    {
        while( !IS_CHAR(str[index]) )
        {
            index += 1;
        }       
    
        for(j = index, k = 0; str[j] != '\0'; index++, j++, k++)
        {
            str[k] = str[j];
            if( IS_CHAR(str[k]) )
                last_char = index;
        }
        printf("\n Last character index : %d \n", last_char);  
        str[last_char] = '\0';
    }
    
    printf("\n The String is already trimmed \n");
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
    bin_sort_main();
}
#endif   /* Ending the Relocatable OBJECTS*/

