#include "array_linkedlist.h"
#include <stdio.h>

Rectangle *rlist_head;                                    /* Pointer Variable of return-type Rectangle(struct) */
Rectangle rpool_nodes[POOLSIZE];                           /* array of return-type Rectangle(struct) */

//Rectangle *rpool_rect;

void clear_node(Rectangle *);
void *init_rpool(Rectangle **);
void display_rpool(Rectangle *);

Rectangle *free_pool_node(Rectangle **rpool_ptr,Rectangle *free_node );
Rectangle *alloc_pool_node(Rectangle **rpool_rect);

/* Main Function */
int main()
{
    //printf("\n FILE: %s \n LINE : %s \n TIME : %s", __FILE__, __LINE__, __TIME__);
    int i;
    rlist_head = &rpool_nodes[0];
    Rectangle *node[10];
    init_rpool(&rlist_head);
    display_rpool(rlist_head);                  /* Calling the Display Function */
    
    rlist_head -> id = 1;
    for(i = 0;i < 10; i++)
    {
        node[i] = alloc_pool_node(&rlist_head);
        printf("\n %d.Pool Index : %x -- %x \n",i,node[i], &(rpool_nodes[node[i] -> pool_index]));
        display_rpool(rlist_head);                  /* Calling the Display Function */
    
    }
    for(i=0; i<10; i++)
    {
    	if(node[i] != &(rpool_nodes[node[i] -> pool_index]))
    	{
            printf(" \n Address Mismatch \n");
    	}
    }
                     
                     /* Calling the Display Function */
    for(i=9; i>=0; i--)
    {
    	free_pool_node(&rlist_head, node[i]);
    }       /* Calling the Free Pool Function */
    display_rpool(rlist_head);

}


/* Function to free the node allocated to someone of the structure */
Rectangle *free_pool_node(Rectangle **rpool_ptr,Rectangle *free_node )
{
    
    free_node -> next = *rpool_ptr;
    *rpool_ptr = free_node;
}

/* Function to allocate the node to someone of type structure */
Rectangle *alloc_pool_node(Rectangle **rpool_pptr)
{
    
    Rectangle *node_ptr;
    node_ptr = *rpool_pptr;
    *rpool_pptr = node_ptr -> next;
    node_ptr -> next = NULL;
    return node_ptr;
}

/* Function to Clear all the elements of Array - Linked-list */
void clear_node(Rectangle *r_ptr)
{
    int i;
    r_ptr -> id = 0;
    for(i = 0; i < VTX_COUNT; i++)
    {	
	r_ptr -> vertex[i].x = 0;
	r_ptr -> vertex[i].y = 0;
    }
}

/* Function to implement Linked-list for an Array */
void *init_rpool(Rectangle **rpool_pptr)
{
    int index;
    //rpool_nodes = (Rectangle *) malloc(sizeof(Rectangle)*(POOLSIZE));
    for(index = 0;index < POOLSIZE - 1; index++)
    {
        clear_node(&rpool_nodes[index + 1]);
        rpool_nodes[index].pool_index = index;
	rpool_nodes[index].next = &rpool_nodes[index + 1];
    }
    rpool_nodes[index].next = NULL;
    //rlist_head = &rpool_nodes[0];
    *rpool_pptr = &rpool_nodes[0];    /* To assign the HEADER Pointer */
} 


/* Function to Display the Array like Linked-list */
void display_rpool(Rectangle *rlist_head)
{
    int index, count = 0;
    while(rlist_head -> next != NULL)
    {
        count += 1;
	rlist_head++;
	//printf("\n X and Y co-ordinates of Rectangle are : \n (X,Y) = (%d,%d)", rlist_head->vertex[index].x, rlist_head->vertex[index].y);
    }
    printf(" Number of elements are : %d ", count);
}


