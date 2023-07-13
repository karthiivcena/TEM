#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main()
{
    long int time_stamp = time(NULL);
    printf("\n %lu \n", time_stamp);
    
    char *time = ctime(&time_stamp);
    printf("\n Actual Time : %s \n", time);
    
    struct timeval tv;
    gettimeofday(&tv, NULL);
    
    printf("Seconds since Jan. 1, 1970: %ld\n", tv.tv_sec);
    return 0;
    
    return 0;
}
