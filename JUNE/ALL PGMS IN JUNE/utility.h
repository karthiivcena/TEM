#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "array_linkedlist.h"

#define TO_LOWER_(c) (((c) >= 'A' && (c) <= 'Z') ? (c) + ('a'-'A') : c)
#define TO_UPPER_(c) (((c) >= 'a' && (c) <= 'z') ? (c) - ('a'-'A') : c)

/* Macros for utility.c */
#define SIZE 120
#define POSITIVE {'+1'}
#define NEGATIVE {'-1'}
#define START 1
#define NOT_START 0
#define PRESENT 1
#define NOT_PRESENT 0

/* MACROS FROM state_trans.c */
#define STATE_A ('A')
#define STATE_B ('B')
#define STATE_C ('C')
#define STATE_D ('D')
#define STATE_E ('E')


/* MACROS FROM UTILITY_CODE_TEST */
#define BUF_MAX_SIZE 1024
#define IS_WHITE_SPACE(c) ((c == ' ' || c=='\t' || c == '\n' || c == '\0') ? 1 : 0)
#define WORD_IN 1
#define WORD_OUT 0

/* MACROS FOR BIG ENDIAN-LITTLE ENDIAN.C */
#define BIG_ENDIAN 1
#define LITTLE_ENDIAN 0;

#define IS_BIG_ENDIAN (get_endian() == BIG_ENDIAN) 
#define IS_LITTLE_ENDIAN (get_endian() == LITTLE_ENDIAN)


extern "C"
{
/* ALL C MAIN FUNCTIONS */
extern int state_trans_main();
extern int utility_main();
extern int count_words_main();
extern int array_list_main();
extern int utilities_main();
extern int valist_test_main();
extern int fn_stack_main();
extern int set_bit_main();
extern int big_little_endian_main();
extern int sort_bin_main();
}
extern int oops_cpp_main();

/* Function of state_trans.c */
extern int transition(char state,int c);

/* Functions of utility.c */
extern int asci_to_int (char *str);
extern char to_lower_char (char c);
extern char to_upper_char (char c);
extern void string_to_upper (char *str);
extern void string_to_lower (char *str);
extern void string_copy (char *dis, char *source);
extern void mem_copy(char *dis, char *src, int size);
extern void display_mem(char *str, int arr_size);
extern char *str_cat(char *str1, char *str2);
extern void swap(char c1,char c2);
extern void mem_sets(char *ptr,char c, int size);

/* Functions of count_words.c */
extern int getword(char *buf);   
extern int getchars(char *buf, int max);

/* Functions of fn_stack_frame_test.c */
extern int violet(int a, int b);
extern char indigo(char i1, int i2);
extern int *blue(char *b1, short int b2);
extern char *green(int g1[], char *g2);
extern float yellow(char y1[], char *y2);
extern int orange(char *o1, int o2, float o3);
extern double red(int *r1,char *r2,int *r3);

/* Function of bigendian_littleendian.c */
extern int get_endian();
extern int str_cmp(char *s1, char *s2);
extern int str_substr(char *s1,char *s2);

/* Function of set_bit.c */
extern int bin(int no);
extern int set_number(int a, int position);
extern int clear_bit(int a, int position);

#endif /* ENDING UTILITY_H */
