/*
    Author : Aziz Amerul Faozi
    Filename : mutex_dynamic.
    Desciription : just learn how to use mutex, recite from the book.
*/

#include<pthread.h>

#include "errors.h"

typedef struct my_struct_tag{
    pthread_mutex_t mutex;
    int value;
} my_struct_t;



int main(int argc, char *argv[]){

    my_struct_t *data;
    int status;

    data = malloc(sizeof(my_struct_t));
    if (data==NULL){
        errno_abort("Mengalokasikan struktur");
    }
    status = pthread_mutex_init(&data->mutex, NULL);

    if(status!=0){
        err_abort(status, "Inisiasi mutex");
    }

    status = pthread_mutex_destroy(&data->mutex);

    if(status!=0){
        err_abort(status, "Destroy mutex");
    }

    (void)free(data);



    printf("hai");
    return status;
}