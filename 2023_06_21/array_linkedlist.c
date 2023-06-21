#include "array_linkedlist.h"
#include <stdio.h>

Rectangle *rlist_head;                                    /* Pointer Variable of return-type Rectangle(struct) */
Rectangle rpool_rect[POOLSIZE];                           /* array of return-type Rectangle(struct) */

void clear_node(Rectangle *);
void *init_rpool(Rectangle **);
void display_rpool(Rectangle *);

/* Main Function */
int main()
{
    int *rlist_head = &rpool_rect;
    init_rpool(test_arr_ptr_p);
    display_rpool(rpool_ptr, POOLSIZE);
}

/* Function to Clear all the elements of Array - Linked-list */
void clear_node(Rectangle *r_ptr)
{
    int i;
    r_ptr -> id = 0;
    for(i = 0; i < VTX_COUNT; i++)
    {	
	r_ptr --> vertex[i].x = 0;
	r_ptr --> vertex[i].y = 0;
    }
}

/* Function to implement Linked-list for an Array */
void *init_rpool(Rectangle **rpool_rect)
{
    int index;
    
    for(index = 0;index < POOLSIZE - 1; index++)
    {
        clear_node(&rpool_rect[index]);
	rpool_rect[index].next = &rpool_rect[index + 1];
    }
    rpool_rect[index].next = NULL;
    //rlist_head = &rpool_rect[0];
    *rpool_rect = &rpool_rect[0];
}

/* Function to Display the Array like Linked-list
void display_rpool(Rectangle *rpool_ptr,int p_size)
{
    
    int index, count;
    while(rpool -> next != NULL)
    {
        count += 1;
	rpool += 1;
	printf("\n X and Y co-ordinates of Rectangle are : \n (X,Y) = (%d,%d)", rpool_ptr.vertex[index].x, rpool_ptr.vertex[index].y);
    }
    printf(" Number of elements are : %d ", count);
}


