extern "C"
{

#include<stdio.h>

static int gs_my_global_var = 10;
int global_var = 20;

int violet(int a, int b);
char indigo(char i1, int i2);
int *blue(char *b1, short int b2);
char *green(int g1[], char *g2);
float yellow(char y1[], char *y2);
int orange(char *o1, int o2, float o3);
double red(int *r1,char *r2,int *r3);

int fn_stack_main()
{
    printf("\n Printing the Global Variable : %d \n", global_var);
    printf("\n Printing the Static Global Variable : %d \n", gs_my_global_var);
    violet(5,6);
    return 0;
}

int violet(int a, int b)
{
    printf("Printing Violet %d\n Calling Indigo\n", a + b);
    char ind = indigo('I', 10);
    return ind;
}

char indigo(char i1, int i2)
{
    printf("Printing Indigo \n%c\n%d\n Calling Blue\n", i1, i2);
    blue(&i1, 2);
    return i1;
}

int *blue(char *b1, short int b2)
{
    char a = '5';
    b1 = &a;
    int i1 = 1;
    int *p;
    p = &i1;
    int gg[3] = {1, 2, 3};
    printf("Printing Blue\n%c\n%d\n Calling Green\n", *b1, b2);
    green(gg, b1);
    return p;
}

char *green(int g1[], char *g2)
{    
    char gr = 'G';
    g2 = &gr;
    char cc[3] = {'A','B','C'};
    printf("Printing Green\n Calling Yellow \n");
    yellow(cc , g2);
    return g2;
}

float yellow(char y1[], char *y2)
{
    float f=1.21;
    printf("Printing Yellow \n Calling orange\n");
    orange(y2, 5, 1.12);
    return f;
}

int orange(char *o1, int o2, float o3)
{
    printf("Printing Orange \n Calling Red \n");
    char cr='R';
    red(&o2, &cr,&o2);
    return o2;
}

double red(int *r1,char *r2,int *r3)
{
    printf("Printing Red \n End of the functions \n");
    char *ptr = (char *) 0x123;
    //printf("%", ptr);
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
