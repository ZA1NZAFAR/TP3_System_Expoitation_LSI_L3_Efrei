#include <stdio.h>
#include <pthread.h>

void *thread1_function(void *param);
void *thread2_function(void *param);
void *thread3_function(void *param);
void Td3Q1();


int varGlobal = 51;

int main() {
    printf("Hello, World!\n");
    Td3Q1();
    return 0;
}


void Td3Q1(){
    pthread_t thread1, thread2, thread3;
    pthread_create(&thread1, NULL, thread1_function, NULL);
    pthread_create(&thread2, NULL, thread1_function, NULL);
    pthread_create(&thread3, NULL, thread1_function, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
}

void *thread1_function(void *param){
    int local = 511;
    printf("Thread 1 is running\n");
    //varGlobal = 99;

    printf("Thread 1 is exiting %d \n",varGlobal);

    printf("Thread 1 is exiting %d \n",local);
    return NULL;
}


void *thread2_function(void *param){
    int local = 532;
    printf("Thread 2 is running\n");
    printf("Thread 2 is exiting %d \n",varGlobal);
    printf("Thread 2 is exiting %d \n",local);
    return NULL;
}


void *thread3_function(void *param){
    int local = 5432;
    printf("Thread 3 is running\n");
    varGlobal = 99;
    printf("Thread 3 is exiting %d \n",varGlobal);
    printf("Thread 3 is exiting %d \n",local);
    return NULL;
}


