#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <stdio.h>

#define SIZE 100
#define TO_LOWER_(c) (((c) >= 'A' && (c) <= 'Z') ? (c) + ('a'-'A') : c)
#define TO_UPPER_(c) (((c) >= 'a' && (c) <= 'z') ? (c) - ('a'-'A') : c)

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

#endif /* ENDING UTILITY_H */
