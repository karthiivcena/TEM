#ifndef _SET_CLEAR_H_
#define _SET_CLEAR_H_


#define set_number(a,position) (a | (1 << position )) 
#define clear_bit(a,position) (set & (~ (1 << position)))

#endif //_SET_CLEAR_H_
