#include <stdio.h>
#include <pthread.h>

#define cnt_thrd 10
pthread_mutex_t lock;
int cnt=0;
void *readf(void *id)
{
    pthread_mutex_lock(&lock);
    printf("read by %d count is %d \n",(*((int *)id)),cnt);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}
void * writef(void *id)
{
    pthread_mutex_lock(&lock);
    cnt++;
    printf("write by %d count is %d \n",(*((int *)id)),cnt);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}
int main()
{
    pthread_mutex_init(&lock,NULL);
    pthread_t read[cnt_thrd],write[cnt_thrd];
    int arr1[cnt_thrd];
    for (int i=0;i<cnt_thrd;i++)
    {
        arr1[i]=i;
    }
    for (int i=0;i<cnt_thrd;i++)
    {
        pthread_create(&read[i],NULL,readf,(void *)&arr1[i]);
    }
    for (int i=0;i<cnt_thrd;i++)
    {
        pthread_create(&write[i],NULL,writef,(void *)&arr1[i]);
    }
    for (int i=0;i<cnt_thrd;i++)
    {
        pthread_join(read[i],NULL);
    }
    for (int i=0;i<cnt_thrd;i++)
    {
        pthread_join(write[i],NULL);
    }
    pthread_mutex_destroy(&lock);
    return 0;
    


}