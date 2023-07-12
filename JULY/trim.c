#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define IS_SPACE(c) (c==' ')||(c=='\n')||(c=='\t') ? 1:0

char* trim(char* str) {
    long int len = strlen(str);

    // Trim leading whitespace
    char* start = str;
    while (isspace(*start))
        ++start;

    // Trim trailing whitespace
    if (len != 0) {
        char* end = str + len - 1;
        while (end > start && isspace((unsigned char)*end))
            --end;
        end[1] = '\0';
    }

    return start;
}

int main() {
    char str[] = "   Hello, World!   ";
    char* trimmed = trim(str);
    printf("'%s'\n", trimmed);

    return 0;
}

