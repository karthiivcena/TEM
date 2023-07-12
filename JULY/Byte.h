#ifndef _BINARY_H_
#define _BINARY_H_

#include <iostream>

#define STATUS_FAILURE (-1)
#define STATUS_SUCCESS (1)


class Byte
{

private:
    unsigned char bit_0:1;
    unsigned char bit_1:1;
    unsigned char bit_2:1;
    unsigned char bit_3:1;
    unsigned char bit_4:1;
    unsigned char bit_5:1;
    unsigned char bit_6:1;
    unsigned char bit_7:1;
    
public:
    int setBit(unsigned int pos, unsigned int value);
    char* display();
    
};

#endif
