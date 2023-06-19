/* Program to count the number of wordsin the program */

#include <stdio.h>
#define BUF_MAX_SIZE 1024
#define IS_WHITE_SPACE(c) ((c == ' ' || c=='\t' || c == '\n' || c == '\0') ? 1 : 0)
#define WORD_IN 1
#define WORD_OUT 0

int getword(char *buf);    /* Function declaration */
int getchars(char *buf, int max);

int char_count = 0;

int line_count = 0;

/*Main Function*/
int main(int charc, char* argv)
{
    int ch = 0;
    int cc = 0;
    char c;
    char buffer[BUF_MAX_SIZE]; 
                                                                                          /* Assigning the buffer */
    printf( "Enter the sentences to get the count of characters: \n Press Ctrl + d to end the sentences \n"); 
    int ln = getchars(buffer, BUF_MAX_SIZE); 
   
    printf("\n Number of characters are %d \n", ln);
    printf("\n String : %s \n", buffer);
    
    ch = getword(buffer);
    printf("\n Number of words are : %d \n", ch);
    return 0;
}

/* Function to count the number of characters from the command line */
int getword(char *buf)
{
    int word_count = 0;
    int state = WORD_OUT;
    int i = 0;
    for (i; buf[i] != '\0'; i++)
    {
    	if (state == WORD_OUT)
    	{
        	if (!IS_WHITE_SPACE(buf[i]))
        	{
       		     state = WORD_IN;
           	     
        	}
    	}
    	else if (state == WORD_IN )
    	{
        	if (IS_WHITE_SPACE(buf[i]))
            	{    state = WORD_OUT;
            	     word_count += 1;
            	}  	    
    	}
    }
    if ( state == WORD_IN )
        word_count += 1;
    return word_count;
}


int getchars(char *buf, int max)
{
    int i;
    char c;
    for(i = 0;(c=getchar()) != EOF && i < max ; i++)
    {
            buf[i] = c;
    }
    buf[i] = '\0';
    return i;
}

