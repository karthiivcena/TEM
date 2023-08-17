// C Program for Message Queue (Writer Process)

#include "ipc.h"

key_t key;
int msgid;

char buffer[100];

/* Function to Send the data to the receiver */
void writer()
{
    message.mesg_type = TRUE;
   
    msgsnd(msgid, &message, sizeof(message), 0);
    
}

/* Function to receive the data from the sender */
void reader()
{
    msgrcv(msgid, &message, sizeof(message), TRUE, FALSE);
    
    printf("Data Received is : %s \n", message.mesg_text);
    
    msgctl(msgid, IPC_RMID, NULL);
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
     
    while(index < 10)
    {
    	sprintf(message.mesg_text, " %s from index : %d", argv[1], index);
        writer();
        index++;
        //sleep(1);
    }
     
    return 0;
}
