#include "queue_doubly_ll_implementation.h"

Queue::Queue()
{
    headPtr = NULL;
    tailPtr = NULL;
    nodeCount = 0;
}

/* enQueue function to add to doubly linked list */
int Queue::enQueue(char *msg, int size)
{
    NODE *nodePtr;
    NODE *newnode = (NODE *)malloc(sizeof(NODE)+size);
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->size = size;
    
    if(!msg)
    {
        return -2;
    }
    memcpy(newnode->data, msg, size);
    
    if(headPtr == NULL && tailPtr == NULL)
    {
 	headPtr = newnode;
	tailPtr = newnode;
    }
    else    
    {
	tailPtr->next = newnode;
	newnode->prev = tailPtr;
	tailPtr = newnode;
	
    }
    nodeCount += 1;
    return 0;
}

/* deQueue function to delete a node to doubly linked list */
int Queue::deQueue(char *msgBuffer, int *size)
{
    NODE *nptr;
	
    if(headPtr == NULL)
	return -1;
	
    nptr = headPtr;	
    headPtr = nptr->next;
    if(headPtr != NULL)
    {
        headPtr->prev = NULL;
    }
    else
    {
        tailPtr = NULL;
    }
    nptr->next = NULL;
    memcpy(msgBuffer, nptr->data, nptr->size);
    *size = nptr->size;
    free(nptr);
    cout << msgBuffer;
    
    nodeCount -= 1;
    return 0;
}

/* Display Function */
void Queue::display()
{
    NODE *ptr = headPtr;
    cout << "\n Node Count: ", nodeCount;
    if(headPtr == NULL)
	cout<<"\n List is Empty \n"<<endl;
    else
    {
        while(ptr != NULL)
	{
	    cout<<"\n Data in the list: "<<ptr->data<<endl;
   	    ptr = ptr->next;
	}
    }	
}

/* Main Function */
int main()
{
    char ch = 'c';
    char cs ='p';
    char ce = 'p';
    char t;
    Queue q1 = Queue();
    if(q1.enQueue(&ch, sizeof(ch)) == 0)
	printf("\n Insert1 Successfull \n");
		
    if(q1.enQueue(&cs, sizeof(cs)) == 0)
	printf("\n Insert2 Successfull \n");
		
    if(q1.enQueue(&ce, sizeof(ce)) == 0)
	printf("\n Insert3 Successfull \n");
		
    q1.display();
	
    int sis;
    if(q1.deQueue(&t, &sis) == 0)
	printf("\n Delete Successfull\n");
		
    if(q1.deQueue(&t, &sis) == 0)
	printf("\n Delete Successfull\n");
		
    if(q1.deQueue(&t, &sis) == 0)
	printf("\n Delete Successfull \n");
	
    q1.display();
		
    return 0;	
}
    
    
	
    
    
    
