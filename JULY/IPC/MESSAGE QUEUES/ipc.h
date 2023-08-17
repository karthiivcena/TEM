#ifndef _IPC_H_
#define _IPC_H_

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TRAVERSE 3

#define MSGQ_KEY_STR "msg_key"
#define PROJ_ID 99

#define TRUE 1
#define FALSE 0

#define MAX 15

extern key_t key;
extern int msgid;

extern char str[];

// structure for message queue
struct mesg_buffer 
{
	long mesg_type;
	char mesg_text[100];
	int pid;
} message;


#endif
