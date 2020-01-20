#include<pthread.h>

#include "errors.h"

typedef struct my_struct_tag{
    pthread_mutex_t mutex;
    int value;
} my_struct_t;



my_struct_t dataad = {PTHREAD_MUTEX_INITIALIZER, 0};

int main(int argc, char *argv[]){

    printf("hai");
    return 0;
}