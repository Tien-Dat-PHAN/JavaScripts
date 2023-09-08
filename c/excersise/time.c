#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>

int main(void){

    time_t  timeval; 
    time(&timeval);

    printf("This program have been written on %s", ctime(&timeval));


    struct timeval *p_tv = malloc(sizeof(struct timeval));
    int error = gettimeofday(p_tv, NULL);
    if (!error ){
        printf("%ld\n", p_tv->tv_sec);
        printf("%ld", p_tv->tv_usec);
        
    }
    free(p_tv);
    return error;
}
