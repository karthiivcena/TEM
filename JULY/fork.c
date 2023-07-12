#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int gl_var = 99;

/* Fork Function to create parent and child process */
void fork_fun()
{
    printf("\n Global Var = %d ", gl_var);
    
    int pid;
    char c;
    pid = fork();
    printf("\n PID which we got is : %d \n", pid);
    
    if(pid > 0)
    {
        gl_var = 9;
        printf("\n Global Variable : %d", gl_var);
        printf("\n Parent : Child PID = %d ", pid);
        pid = wait();
        printf("\n Parent : Child %d exited \n\n", pid);
        scanf("%c", &c);
    }
    else
    {
        gl_var = 999;
        printf("\n Global Variable : %d", gl_var);
        printf("\n In Child Process \n\n");
        scanf("%c", &c);
        exit(0);
    }
}

/* Function to write your own SIGNAL HANDLER */
void my_sig_int_handler(int signal)
{
    printf("\n Entered Signal Interrupt Handler \n");
    if(signal == SIGSEGV)
    {
        printf("\n Interrupt Executing \n Signal Received : %d \n", signal);
        exit(0);
    }
    printf("\n Invalid Signal \n");
}

/* Function to wite the general signal handler */ 
void my_gen_handler(int signal)
{
    printf("\n Entered General Handler \n");
    if(signal == SIGTSTP)
    {
        printf("\n Stopped Interupt \n Signal Received : %d \n", signal);
        exit(0);
    }
    if(signal == SIGCHLD)
    {
        printf("\n Child Interrupt \n Signal Received : %d \n", signal);
        exit(0);
    }
}

/* Main Function */
int main()
{
    int sig;
    printf("\n When the fork is called, two process are created, one for parent and the other for child\n The child process will have pid = 0 at the beginneing to indivcate that it is a child process \n ");

    fork_fun();
    printf("\n Enter the SIGNAL NUMBER TO INTERRUPT \n");
    scanf("%d", &sig);
    signal(SIGSEGV, my_sig_int_handler);
    signal(SIGCHLD, my_gen_handler);
    //my_sig_int_handler(sig);
    //char *ptr = 10;
    return 0;
}
    
