#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

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

// TP3 Q2
//#define bloquer(x) sem_wait(x)
//#define debloquer(x) sem_post(x)
//
//
//sem_t sem1 , sem2;
//int ret;
//
//
//
//void *thread1_function(void *param) {
//    printf("Je \n");
//    debloquer(&sem1);
//    bloquer(&sem2);
//    printf("mes \n");
//    debloquer(&sem1);
//    return NULL;
//}
//
//
//void *thread2_function(void *param) {
//    bloquer(&sem1);
//    printf("synchronise \n");
//    debloquer(&sem2);
//    bloquer(&sem1);
//    printf("threads \n");
//    return NULL;
//}
//
//void Td3Q2() {
//    sem_init(&sem1, 0, 0);
//    sem_init(&sem2, 0, 0);
//    pthread_t thread1, thread2;
//    pthread_create(&thread1, NULL, thread1_function, NULL);
//    pthread_create(&thread2, NULL, thread2_function, NULL);
//    pthread_join(thread1, NULL);
//    pthread_join(thread2, NULL);
//}

// TP3 Q3
//pthread_barrier_t barrier; // the barrier synchronization object
//
//void *
//thread1(void *not_used) {
//    time_t now;
//    char buf[27];
//
//    time(&now);
//    printf("thread1 starting at %s", ctime_r(&now, buf));
//
//    // do the computation
//    // let's just do a sleep here...
//    sleep(20);
//    pthread_barrier_wait(&barrier);
//    // after this point, all three threads have completed.
//    time(&now);
//    printf("barrier in thread1() done at %s", ctime_r(&now, buf));
//}
//
//void *
//thread2(void *not_used) {
//    time_t now;
//    char buf[27];
//
//    time(&now);
//    printf("thread2 starting at %s", ctime_r(&now, buf));
//
//    // do the computation
//    // let's just do a sleep here...
//    sleep(40);
//    pthread_barrier_wait(&barrier);
//    // after this point, all three threads have completed.
//    time(&now);
//    printf("barrier in thread2() done at %s", ctime_r(&now, buf));
//}
//
//main() // ignore arguments
//{
//    time_t now;
//    char buf[27];
//
//    // create a barrier object with a count of 3
//    pthread_barrier_init(&barrier, NULL, 3);
//
//    // start up two threads, thread1 and thread2
//    pthread_create(NULL, NULL, thread1, NULL);
//    pthread_create(NULL, NULL, thread2, NULL);
//
//    // at this point, thread1 and thread2 are running
//
//    // now wait for completion
//    time(&now);
//    printf("main () waiting for barrier at %s", ctime_r(&now, buf));
//    pthread_barrier_wait(&barrier);
//
//    // after this point, all three threads have completed.
//    time(&now);
//    printf("barrier in main () done at %s", ctime_r(&now, buf));
//}
int tab[10];
sem_t sem1, sem2;
#define bloquer(x) sem_wait(x)
#define debloquer(x) sem_post(x)

void *threadEcriture(void *param) {
    for (int i = 0; i < 10; ++i) {
        bloquer(&sem2);
        tab[i] = i;
        debloquer(&sem2);
        bloquer(&sem1);
    }
}


void *threadLecture(void *param) {

    for (int i = 0; i < 10; ++i) {
        bloquer(&sem2);
        printf("%d\n", tab[i]);
        debloquer(&sem1);
    }
}

void main() {
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 0);
    pthread_t threadEcrituret, threadLecturet;
    pthread_create(&threadLecturet, NULL, threadLecture, NULL);
    pthread_create(&threadEcrituret, NULL, threadEcriture, NULL);
    pthread_join(threadEcrituret, NULL);
    pthread_join(threadLecturet, NULL);

}

