//
//  main.c
//  Chapter18-2.Create_Thread
//
//  Created by LEE on 2018. 5. 24..
//  Copyright © 2018년 LEE. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>

void* pthread_main(void *arg)
{
    int i;
    int cnt = *((int*)arg);
    for(i=0; i<cnt; i++)
    {
        sleep(1); puts("running thread");
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    pthread_t t_id;
    int thread_param = 5;
    
    if(pthread_create(&t_id,NULL,pthread_main,(void*)&thread_param)!= 0)
    {
        puts("pthread_create() error");
        return -1;
    };
    
    sleep(10); puts("end of main");
    return 0;
}

