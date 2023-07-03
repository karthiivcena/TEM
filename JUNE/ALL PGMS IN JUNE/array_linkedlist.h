#ifndef _ARRAY_LINKEDLIST_H_
#define _ARRAY_LINKEDLIST_H_

#define POOLSIZE 512
#define VTX_COUNT 4
#define DESC_LEN 31

#include <stdio.h>

typedef struct Point_t
{
    int x;
    int y;
}Point;

typedef struct Rectangle_t
{
    Point vertex[VTX_COUNT];
    char desc[DESC_LEN];
    int id;
    int pool_index;
    struct Rectangle_t *next;
    struct Rectangle_t *prev;
}Rectangle;


#endif /* This endif is for _ARRAY_LIST_H_ */


