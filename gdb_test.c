#include<stdio.h>

void myfunction()
{
    printf( " This is my print function\n");

}


int main()
{
    int i = 0;
    int count = 0;
    for (i = 0; i < 10; i++) 
    {
        count += i;
    }
    myfunction();



    return count;
}
     
