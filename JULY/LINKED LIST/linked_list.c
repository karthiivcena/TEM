#include "linked_list_test.h"

// insert node at head
int addlistnodeAtFirst(LLNODE **lhead, LLNODE *newnode)
{
	LLNODE *temp_node = (LLNODE *)malloc(sizeof(LLNODE));
	memcpy(temp_node, newnode, sizeof(LLNODE));
	if(*lhead == NULL)
	{
		*lhead = newnode;
	}
	else
	{
		newnode->next = *lhead;
		*lhead = newnode;
	}
	return 0;
}

// insert node at sorted key value
int addListNode(LLNODE **lhead, LLNODE *node)
{
	LLNODE **nextpptr;
	LLNODE *nodeptr;
	LLNODE *newnode;
	
	if(!lhead || !node)
	{
	    return -1;
	}
	
	nextpptr = lhead;
	nodeptr = *lhead;
	
	while(nodeptr)
	{
		if(node->data < nodeptr->data)
		{
			break;
		}
		nextpptr = &(nodeptr->next);
		nodeptr = nodeptr->next;
	}
		
	newnode =(LLNODE *) malloc(sizeof(LLNODE));
	if(!newnode)
	    return -2;
	    
	memcpy(newnode, node, sizeof(LLNODE));
	
	newnode->next = *nextpptr;
	*nextpptr = newnode;
	return 0;
}

// insert node at end of list
int add_last(LLNODE **lhead, LLNODE *node)
{
	LLNODE **nextpptr;
	LLNODE *nodeptr;
	LLNODE *newnode;
	nextpptr = lhead;
	nodeptr = *lhead;
	
	newnode =(LLNODE *) malloc(sizeof(LLNODE));
	memcpy(newnode, node, sizeof(LLNODE));
	
	while(nodeptr)
	{
		nextpptr = &(nodeptr->next);
		nodeptr = nodeptr->next;
	}
	
	*nextpptr = newnode;
	return 0;
}		

// delete node at sorted key value
int delete_list_node(LLNODE **lhead, int key)
{
	LLNODE **nextpptr;
	LLNODE *nodeptr;
	
	if(!lhead || !key)
	{
	    return -1;
	}
	
	nextpptr = lhead;
	nodeptr = *lhead;
	
	while(nodeptr)
	{
		if(nodeptr->data == key)
		{
			*nextpptr = nodeptr->next;
			free(nodeptr);
			return 0;
		}
		nextpptr = &(nodeptr->next);
		nodeptr = nodeptr->next;
	}
	return -1;
}

// delete node at head
int delete_first(LLNODE **lhead)
{
	LLNODE *nptr;
	nptr = *lhead;
	
	if(*lhead == NULL)
		return -1;
		
	*lhead = nptr->next;
	return 0;
	
}

// delete node at end of list
int delete_last(LLNODE **lhead)
{
	LLNODE **nextpptr;
	LLNODE *nodeptr;
	
	if(!lhead)
	{
	    return -1;
	}
	
	nextpptr = lhead;
	nodeptr = *lhead;
	
	while(nodeptr->next != NULL)
	{
		nextpptr = &(nodeptr->next);
		nodeptr = nodeptr->next;
	}
	
	*nextpptr = NULL;
	free(nodeptr);
	return 0;
}


void display(LLNODE **lhead)
{
	if(*lhead == NULL)
		printf("empty\n");
	LLNODE *ptr = *lhead;
	int i=0;
	while(ptr !=NULL)
	{
		printf("data at %d node is %d\n",i,ptr->data);
		ptr = ptr->next;
		i++;
	}
}

int main()
{
	LLNODE *head = NULL;
	LLNODE node1, node2, node3, node4, node5;
	node1.data = 4;
	node1.next = NULL;
	if(addListNode(&head, &node1) == 0)
		printf("firstnode added!!\n");
		
	node2.data = 1;
	node2.next = NULL;
	if(addListNode(&head, &node2) == 0)
		printf("firstnode added!!\n");
		
	
	node3.data = 3;
	node3.next = NULL;		
	if(addListNode(&head, &node3) == 0)
		printf("done!!\n");
		
		
	node5.data = 5;
	node5.next = NULL;		
	if(addListNode(&head, &node5) == 0)
		printf("done!!\n");
		
	display(&head);
		
	if(!delete_list_node(&head, 3))
		printf("deleted!!\n");
		
	node4.data = 2;
	node4.next = NULL;		
	if(addListNode(&head, &node4) == 0)
		printf("done!!\n");
		
	display(&head);
	
	node1.data = 1;
	node1.next = NULL;
	if(addListNode(&head, &node1) == 0)
		printf("node added at head!!\n");
		
	node2.data = 4;
	node2.next = NULL;
	if(add_last(&head, &node2) == 0)
		printf("node added at last!!\n");
		
	display(&head);
	
	if(!delete_first(&head))
		printf("deleted!!\n");
		
	if(!delete_last(&head))
		printf("deleted!!\n");
		
	display(&head);
	
	return 0;
}
		
