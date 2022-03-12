#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>


//TP3 Q1
//int varGlobal = 51;
//void *thread1_function(void *param){
//    int local = 511;
//    printf("Thread 1 is running\n");
//    //varGlobal = 99;
//
//    printf("Thread 1 is exiting %d \n",varGlobal);
//
//    printf("Thread 1 is exiting %d \n",local);
//    return NULL;
//}
//
//
//void *thread2_function(void *param){
//    int local = 532;
//    printf("Thread 2 is running\n");
//    printf("Thread 2 is exiting %d \n",varGlobal);
//    printf("Thread 2 is exiting %d \n",local);
//    return NULL;
//}
//
//
//void *thread3_function(void *param){
//    int local = 5432;
//    printf("Thread 3 is running\n");
//    varGlobal = 99;
//    printf("Thread 3 is exiting %d \n",varGlobal);
//    printf("Thread 3 is exiting %d \n",local);
//    return NULL;
//}
//void Td3Q1(){
//    pthread_t thread1, thread2, thread3;
//    pthread_create(&thread3, NULL, thread3_function, NULL);
//    pthread_create(&thread2, NULL, thread2_function, NULL);
//    pthread_create(&thread1, NULL, thread1_function, NULL);
//    pthread_join(thread1, NULL);
//    pthread_join(thread2, NULL);
//    pthread_join(thread3, NULL);
//}
#define bloquer(x) sem_wait(x)
#define debloquer(x) sem_post(x)


sem_t sem1 , sem2;
int ret;



void *thread1_function(void *param) {
    printf("Je \n");
    debloquer(&sem1);
    bloquer(&sem2);
    printf("mes \n");
    debloquer(&sem1);
    return NULL;
}


void *thread2_function(void *param) {
    bloquer(&sem1);
    printf("synchronise \n");
    debloquer(&sem2);
    bloquer(&sem1);
    printf("threads \n");
    return NULL;
}

void Td3Q2() {
    ret = sem_init(&sem1, 0, 0);
    ret = sem_init(&sem2, 0, 0);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread1_function, NULL);
    pthread_create(&thread2, NULL, thread2_function, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}


int main() {

    printf("Hello, World!\n");
    Td3Q2();
    return 0;
}


