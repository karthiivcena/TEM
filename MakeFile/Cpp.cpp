#include "Cpp.h"

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



