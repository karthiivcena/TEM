#ifndef _SET_CLEAR_H_
#define _SET_CLEAR_H_

/*
#define set_number(a,position) (a | (1 << position ))          /* Using MACRO'S to set a bit to 1 
#define clear_bit(a,position) (set & (~ (1 << position)))      /* Using MACRO'S to clear a bit or set the bit to zero 
*/

#include <stdio.h>
extern int set_number(int a,int position);
extern int clear_bit(int a,int position);
extern void bin(int no);

#endif //_SET_CLEAR_H_
