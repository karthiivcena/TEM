#ifndef _MSG_QUEUE_H_
#define _MSG_QUEUE_H_

#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

enum STATUS
{
    STATUS_INVALID_PARAMETER,
    ADD_NODE_SUCCESSFULL,
    LIST_EMPTY,
    DELETION_SUCCESSFULL
};

typedef struct node_t
{
    struct node_t *prev;
    struct node_t *next;
    int size;
    char data[0];
}NODE;

class Queue
{
    private:
        NODE *headPtr;
        NODE *tailPtr;
        int nodeCount;
        
    public:
        Queue();
        // ~Queue();
	int enQueue(char *msg, int size);
	int deQueue(char *msgBuffer, int *size);
	void display();
};

#endif
