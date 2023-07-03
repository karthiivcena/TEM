extern "C"
{

/* Program to count the number of wordsin the program */
#include "utility.h"

int getword(char *buf);   
int getchars(char *buf, int max);

int char_count = 0;
int line_count = 0;

/* Count Words Main Function*/
int count_words_main()
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

#ifndef RELOCATABLE_OBJ
int main()
{
    count_words_main();
}
#endif  /* Ended DRELOCATE */
}

