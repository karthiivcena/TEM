#ifndef _FN_OPT_OVLD_H_
#define _FN_OPT_OVLD_H_

#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

#define IS_SPACE(c) (c=='\n') || (c== ' ') || (c=='\t') ?1:0

#define STATUS_FAILURE (-1)
#define STATUS_SUCCESS (1)
#define BUFSIZE 128

#define TRUE 1

#define CHECK_BIT(no,pos) ((no & ((0x01) << (pos))))

#define BIT_O (0x01)
#define BIT_1 (0x02)
#define BIT_2 (0x04)
#define BIT_3 (0x08)
#define BIT_4 (0x10)
#define BIT_5 (0x20)
#define BIT_6 (0x30)
#define BIT_7 (0x40)

class Byte
{
private:
    
    
public:
    unsigned char byte;
    Byte();
    Byte(unsigned int k);
    Byte(int j);
    Byte(unsigned char ch);
    Byte(char* st);
        
    int setBit(unsigned int pos, unsigned int value = TRUE);
    int clearBit(unsigned int pos);
    char* getBitStr(char* bitStr);
    char* trim(char *bitStr, char *outStr);
    void displayAllForm();
    void display();
        
    /* Friend function - operator overloading */    
    friend Byte operator + (const Byte &obj1, const Byte &obj2);
        
};

#endif
