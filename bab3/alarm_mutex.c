/*
    Author : Aziz Amerul Faozi
    Description : This code implement alarm with time and mutex, just to learn threading.
*/

#include<pthread.h>
#include<time.h>
#include<errors.h>

typedef struct alarm_tag {
    struct alarm_tag *link;
    int seconds;
    time_t time;
    char message[64];
} alarm_t;

pthread_mutex_t alarm_mutex = PTHREAD_MUTEX_INITIALIZER;

alarm_t *alarm_list = NULL;

void *alarm_thread(void *arg){
    alarm_t *alarm;
    int sleep_time;
    time_t now;
    int status;

    while(1){
        status = pthread_mutex_lock(&alarm_mutex);
        if (status!=0){
            err_abort(status, "Lock mutex");
        }

        alarm = alarm_list;
    }

}