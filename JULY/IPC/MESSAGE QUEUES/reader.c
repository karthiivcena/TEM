/* C Program for Message Queue (Reader Process)  Input from the command line */

#include "ipc.h"

key_t key;
int msgid;

char str[100];

/* Function to Send the data to the receiver */ 
void writer()
{
    
    message.mesg_type = TRUE;
    
    msgsnd(msgid, &message, sizeof(message), 0);
    
    printf("Data sent is : %s \n", message.mesg_text);
    
    memcpy(str, message.mesg_text, sizeof(message.mesg_text));
} 


/* Function to receive the data from the sender */
void reader()
{
    msgrcv(msgid, &message, sizeof(message), TRUE, FALSE);
    
    printf("Data Received is : %s \n",message.mesg_text);
}

/* Main Function */
int main(int argc, char *argv[])
{
    int index, pid;
    index = 1;
    pid = getpid();
    message.pid = pid;
    
    key = ftok(MSGQ_KEY_STR, PROJ_ID);
    msgid = msgget(key, 0666 | IPC_CREAT);
    
    printf("PID from reader : %d \n", message.pid);
    while(index<10)
    {
        reader();
        index += 1;
        
    }
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
