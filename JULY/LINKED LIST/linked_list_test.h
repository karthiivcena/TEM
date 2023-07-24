#ifndef _LINKED_LIST_TEST_H_
#define _LINKED_LIST_TEST_H_

#define SUCCESS 0
#define FAILURE -1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct llnode_t
{
   struct llnode_t *next;
   int data;
}LLNODE;

#endif 
