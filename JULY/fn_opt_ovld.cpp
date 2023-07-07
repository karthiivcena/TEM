#include "fn_opt_ovld.h"

Byte::Byte()
{
    byte = 2;
}

Byte::Byte(int j)
{
    this->byte = (unsigned char) j;
}

Byte::Byte(unsigned int k)
{
    int index;
    this->byte = (unsigned char) k;
}

Byte::Byte(unsigned char ch)
{
    this->byte = ch;
}

Byte::Byte(char* inpStr)
{    
    char outStr[BUFSIZE+1];
    int bit_pos = 0;
    int i;
    
    strncpy(outStr, inpStr, BUFSIZE);
    
    trim(outStr,outStr); 
    int strLen = strlen(outStr);
    
    for(i = 0; i<strLen;i++)
    {
        if(outStr[i] != '0' && outStr[i] != '1')
            assert(0);
    }
    
    int j = strLen-1;
    this->byte = 0;
    
    for(j,bit_pos; bit_pos <= 7; bit_pos++, j--)
    {
        if(outStr[j] == '1')
            setBit(bit_pos);
    }
    cout << "\n Display from the constructor : \n";
    display();
    cout << "\n";
}

/* Function to trim the string */
char* Byte::trim(char *inStr, char *outStr) 
{
    int f_ind = -1;
    int l_ind = -1;
    int i;
    if(!inStr || !outStr)
        return NULL;
    for(i = 0;inStr[i] != '\0';i++)
    {
        if(!(IS_SPACE(inStr[i])))
        {
            if(f_ind == -1)
            {
                f_ind = i;
            }
            l_ind = i;
        }
    }
    for(i = 0; f_ind <= l_ind; i++,f_ind++)
    {
        outStr[i] = inStr[f_ind];
    }
    outStr[i] = '\0';
    return outStr;
}

/* setBit Function */
int Byte::setBit(unsigned int pos, unsigned int value)
{   
    
    if(pos > 7)
        return STATUS_FAILURE;
    if(value)
        byte = (byte | (0x01 << (pos)));
    else
        byte = (byte & (~(0x01 << (pos))));
    return STATUS_SUCCESS;
}


/* Function to get get bits  */
char* Byte::getBitStr(char* bitStr)
{
    int i;
    for(i = 7;i >= 0; i--)
    {
        if(((byte & ((0x01) << (i)))))
           bitStr[i] = '1';
        else
           bitStr[i] = '0';
    }
    bitStr[8] = '\0';
    return bitStr;
}

/* Function to clear the bit */
int Byte::clearBit(unsigned int pos)
{
    if(pos>7)
        return STATUS_FAILURE;
    byte = (byte & (~ (0x01 << (pos))));
    return 1;
}

/* Function to display the buffer */
void Byte::display()
{
    char bitStr[10];
    cout << getBitStr(bitStr) << endl;;
    
}

/* Function to display in binary and hexadecimal form */
void Byte::displayAllForm()
{
    
    char bitStr[10];
    cout << getBitStr(bitStr) << endl;
    printf("\n Printing in Hexadecimal form : %x \n", bitStr);
    
}

/* Friend Function to implement operator overriding for + */
Byte operator + (Byte &o1, Byte &o2)
{
    unsigned int var, carry;
    Byte result;
    var = (unsigned int) o1.byte+(unsigned int) o2.byte;
    result = (unsigned char) (0xff & var);
    
    carry = (0xf00 & var) ? 1:0;
    
    return result;
}
 
    
/* Main Function */
int main()
{
    unsigned int value, position;
    /* Calling all the functions from an object */
    char str[] = "  10110110  ";
    Byte b(str);
    b.setBit(1, 10);
    b.getBitStr(str);
    b.display();
    
    
    /* Strings for operator overloading */
    char str1[10] = "10110011";
    char str2[10] = "10111010";
    //long int ss = 10L;
    Byte o1(str1);
    Byte o2(str2);
    Byte o3;
    
    
    /* Calling the opeartor overloading by objects */
    o3 = o1+o2;
    //o3.display(); 
    o3.displayAllForm();
    
    
    Byte b1(19);
    
    return 0;
}
    
    
