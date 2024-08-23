#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

const int time_sleep_dure=5;
#define maxim(x,y) ((x) > (y) ? (x) : (y))
#define num 5
#define minim(x,y) ((x) < (y) ? (x) : (y))

sem_t chop_stick[num];

void *compute_theory(void *args)
{
    int tedad = *((pthread_t *)args);
    for(;;) 
    {
        printf("Philosopher %d is thinking!\n",tedad+1);
        sem_wait(chop_stick+minim(tedad,(tedad+1)%num));
        sem_wait(chop_stick+maxim(tedad,(tedad+1)%num));
        printf("Philosopher %d is eating using chopstick[%d] and chopstick[%d] :) \n",tedad+1,tedad,tedad+1);
        sleep(time_sleep_dure);
        sem_post(chop_stick+tedad);
        sem_post(chop_stick+((tedad+1)%num));
    }
}

int main()
{
    int i=0;
    while(i<num)
    {    
        sem_init(chop_stick+i, 0,1);
        i++;
    }
    pthread_t id_thread[num];
    int id_tnum[num];
    i=0;
    while(i<num)
    {
        id_tnum[i] = i;
        pthread_create(id_thread + i, NULL, *compute_theory, id_tnum + i);
        i++;
    }
    int j=0;
    while(j<num)
    {
        pthread_join(id_thread[j], NULL);
        j++;
    }
    j=0;
    while(j<num)
    {
        sem_destroy(chop_stick+j);
        j++;
    }
    return 0;
}