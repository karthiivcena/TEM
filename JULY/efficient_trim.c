#include <stdio.h>
#include <string.h>

#define IS_SPACE(c) (c=='\n') || (c== ' ') || (c=='\t') ?1:0

/* Function to trim the string */
char *trim(char *str) 
{
    int len = strlen(str);

    // Trim leading whitespace
    char *start = str;
    while (IS_SPACE(*start))
        ++start;

    // Trim trailing whitespace
    if (len != 0) 
    {
        char *end = str + len - 1;
        printf("\n %c \n", *end);
        while (end > start && IS_SPACE(*end))
            --end;
        end[1] = '\0';
    }

    return start;
}

/* Main Function */
int main() 
{
    char str[] = "   ";
    char* trimmed = trim(str);
    printf("%s\n", trimmed);

    return 0;
}

