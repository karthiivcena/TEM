/* Main File to create demon process */
/* Deamon process is created if the fork is called twice or more in a loop. Then the parent process is killed forcefully...makeing the child process daemon... Even if you terminate the program, the process will still be active */

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <unistd.h>
#include "become_daemon.h"
#include "daemon.c"

int main(int argc, char *argv[])
{
    int ret;
    const char *LOGNAME = "DAEMON_EXAMPLE";
    
    ret = become_daemon(0);
    if(ret)
    {
        syslog(LOG_USER | LOG_ERR, "error starting");
        closelog();
        return EXIT_FAILURE;
    }
    
    openlog(LOGNAME, LOG_PID, LOG_USER);
    syslog(LOG_USER | LOG_INFO, "starting");
    
    while(1)
    {
        sleep(60);
        syslog(LOG_USER | LOG_INFO, "running");
    }
    
    return EXIT_SUCCESS;
}
