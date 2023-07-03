#include "Cpp.h"

/*
extern "C"
{
    int sum(int c, int d)
    {
     	return (c+d);
    }
    
    void fun()
    {
        printf("\n Sum of A and B in C is : %d \n",sum(10,20));
    }
}


int main()
{

    int x,y;
    x = 5;
    y = 5;
    cout << "\n Multiplication of X and Y in C++ is : " <<  multiply(x,y);
    fun();
    return 0;
}

int multiply(int p,int q)
{
    return (p * q);
}

*/


//#include<iostream>
//using namespace std;

 
/*
extern "C" 
{
    #include<stdio.h>
    void CNonMangledfunction()
    {
        printf("A function in C file\n");
    }

    void CMangledfunction()
    {
        printf("A function in C file\n");
    }

}
*/
class MyClass
{
public:
    static void cppMangledfunction()
    {
        cout << "This is a function in cpp file\n";
    }
};

int cpp_main()
{
    MyClass a;
    //CNonMangledfunction();
    a.cppMangledfunction();
    return 0;
}

#ifndef RELOCATABLE_OBJ
int main()
{
    cpp_main();
}
#endif   /* Ending the Relocatable OBJECTS*/



