extern "C"
{
/* Program to execute calling Functions. Taking VIBGYOR as an Example */

#include<stdio.h>

int violet(int a, int b);
char indigo(char i1, int i2);
int *blue(char *b1, short int b2);
char *green(int g1[], char *g2);
float yellow(char y1[], char *y2);
int orange(char *o1, int o2, float o3);
double red(int *r1,char *r2,int *r3);

static int gs_my_global_var = 10;
int global_var = 20;

/* Main function of function stack frame code */
int fn_stack_main()
{
    violet(5,6);
    return 0;
}

int violet(int a, int b)
{
    printf("\n Printing Violet %d \n Calling Indigo \n", a + b);
    char ind = indigo('I', 10);
    return ind;
}

char indigo(char i1, int i2)
{
    int *b_ptr;
    printf("\n Printing Indigo \n %c \n %d \n Calling Blue \n", i1, i2);
    b_ptr = blue(&i1, 2);
    return i1;
}

int *blue(char *b1, short int b2)
{
    char a = '5';
    b1 = &a;
    int i1 = 1;
    int *p;
    p = &i1;
    char *c_ptr;
    int gg[3] = {1, 2, 3};
    printf("\n Printing Blue\n %c \n %d \n Calling Green \n", *b1, b2);
    c_ptr =  green(gg, b1);
    return p;
}

char *green(int g1[], char *g2)
{    
    char gr = 'G';
    g2 = &gr;
    char cc[3] = {'A','B','C'};
    printf("\n Printing Green\n Calling Yellow \n");
    float flo  = yellow(cc , g2);
    return g2;
}

float yellow(char y1[], char *y2)
{
    int ora;
    float f=1.21;
    printf("\n Printing Yellow \n Calling orange \n");
    ora = orange(y2, 5, 1.12);
    return f;
}

int orange(char *o1, int o2, float o3)
{
    double re;
    printf("\n Printing Orange \n Calling Red \n");
    char cr='R';
    re = red(&o2, &cr,&o2);
    return o2;
}

double red(int *r1,char *r2,int *r3)
{
    printf("\n Printing Red \n End of the functions \n");
    //int *ptr = 0x123;
    //printf("%ds", *ptr);
    double re=2.102546;
    return re;
}


#ifndef RELOCATABLE_OBJ
int main()
{
    fn_stack_main();
    return 0;
}
#endif
      
} 
        
