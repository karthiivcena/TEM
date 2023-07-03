extern "C"
{
#include <stdio.h>
#include "utility.h"

int sum(int number, ...)
{
    va_list valist;

    int sum = 0, i;

    va_start(valist, number);
    for(i = 0; i <= number; i++)
        sum += va_arg(valist, int);

    va_end(valist);
    
    return sum;
}

int valist_test_main()
{
    printf(" The sum of elements is : %d \n ", sum(3,1,2,3));
    return 0;
}


#ifndef RELOCATABLE_OBJ
int main()
{
    valist_test_main();
}
#endif  /* Ended DRELOCATE */

}

