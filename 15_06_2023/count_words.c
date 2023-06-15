/* Program to count the number of wordsin the program */

#include <stdio.h>
#define BUF_MAX_SIZE 100

int getcount(char *buf, int max);    /* Function declaration */

/*Main Function*/
int main(int charc, char* argv)
{
    int ch = 0;
    char buffer[BUF_MAX_SIZE];                                                                                        /* Assigning the buffer */
    printf( "Enter the sentences to get the count of characters: \n Press Ctrl + d to end the sentences \n");
    ch = getcount(buffer, BUF_MAX_SIZE);                                                                              /* Calling the getcoun() function */
    printf("\n Number of characters are : %d \n", ch);
    return 0;
}

/* Function to count the number of characters from the command line */
int getcount(char *buf, int max)
{
    char c=0;
    int count=0;
    while((c=getchar())!=EOF && count <= max)
    {
	buf[ count ] = c;
	count += 1;
    }
    if(count == 0)
        return 0;
    return ( count - 1 );
}

        
