#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h> 
#include <stdint.h>
#include <unistd.h>

// to execute use 'cc flie.c -lpthread' 

#define R 5
#define W 5


int readcount;
int writecount;


sem_t wsem;
sem_t rsem;
pthread_mutex_t x; 

int s = 5;


void *reader1(void *a) {
  
  int r = (intptr_t) a;

 
  for (int i = 0; i < 5; i++) {
    
    sem_wait(&rsem);

 
    pthread_mutex_lock(&x);

    
    readcount++;

    if (readcount == 1) {
      sem_wait(&wsem);
    }

    pthread_mutex_unlock(&x);

   
    sem_post(&rsem);

    
    printf("\t\tReader %d is reading: %d\n", r, s);


    pthread_mutex_lock(&x);

   
    readcount--;

  
    if (readcount == 0) {
      sem_post(&wsem);
    }

    pthread_mutex_unlock(&x);

    
    sleep(rand() % 10);
  }
}


void *writer1(void *a) {
  int w = (intptr_t) a;

 
  for (int i = 0; i < 2; i++) {
   
    sem_wait(&wsem);

   
    writecount++;

  
    s += 5;
    printf("Writer %d is writing: %d\n", w, s);

  
    writecount--;

  
    sem_post(&wsem);

   
    sleep(rand() % 10);
  }
}


int main() {
  
  sem_init(&wsem, 0, 1);
  sem_init(&rsem, 0, 1);

  pthread_mutex_init(&x, NULL);


  pthread_t thread_read[R];
  pthread_t thread_write[W];

  for (int i = 0; i < R; i++) {
    pthread_create(&thread_read[i], NULL, reader1, (void *) (intptr_t) i);
  }

  for (int i = 0; i < W; i++) {
    pthread_create(&thread_write[i], NULL, writer1, (void *) (intptr_t) i);
  }

  
  for (int i = 0; i < R; i++) {
    pthread_join(thread_read[i], NULL);
  }

  for (int i = 0; i < W; i++) {
    pthread_join(thread_write[i], NULL);
  }

  
  sem_destroy(&wsem);
  sem_destroy(&rsem);
  pthread_mutex_destroy(&x);

  return 0;
}
