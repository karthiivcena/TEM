/* Header File for the Main File */


#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "array_linkedlist.h"
#include "Byte.h"
#include "set_clear.h"
#include "fn_opt_ovld.h"

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
#include <stdio.h>
#define BUF_MAX_SIZE 1024
#define IS_WHITE_SPACE(c) ((c == ' ' || c=='\t' || c == '\n' || c == '\0') ? 1 : 0)
#define WORD_IN 1
#define WORD_OUT 0

/* ALL C MAIN FUNCTIONS */
extern "C"
{
extern int state_trans_main();
extern int utility_main();
extern int count_words_main();
extern int array_list_main();
extern int valist_test_main();
extern int fn_stack_main();
extern int sort_bin_main();
extern int set_bit_main();
extern int cpp_main();
extern int big_little_endian_main();
}
extern int oop_concept_main(); 
extern int Byte_set_main();
extern int function_overloading_main();

/* ALL C FUNCTIONS WITHOUT MAIN */
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
extern void string_reverse(char str[SIZE]);
extern int sort (int arr[], int length);
extern int str_substr(char *s1,char *s2);
extern int str_cmp(char *s1, char *s2);

extern int get_endian();
extern int str_cmp(char *s1, char *s2);
extern int str_substr(char *s1,char *s2);


#endif /* ENDING UTILITY_H */
