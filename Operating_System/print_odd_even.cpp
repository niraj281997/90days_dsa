#include<iostream>
#include<pthread.h>
pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond  = PTHREAD_COND_INITIALIZER;
using namespace std;
bool printOddFlag = true;
void* f_odd_function(void * arg)
{
    int max = *(int *) arg;
    for(int i = 0;i<max;i++)
    {
        pthread_mutex_lock(&mymutex);
    while (!printOddFlag) {     
      pthread_cond_wait(&cond, &mymutex); 
    }
        printOddFlag=false;
        if(i%2)
        cout<<"Odd Number "<<i<<endl;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mymutex);
    }
return NULL;
}
void* f_even_function(void *arg)
{
    int max = *(int *) arg;
    for(int i = 0;i<max;i++)
    {
        pthread_mutex_lock(&mymutex);
        while (printOddFlag) { 
            pthread_cond_wait(&cond, &mymutex); 
        }
         printOddFlag=true;
        if(i%2==0)
        cout<<"even Number "<<i<<endl;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mymutex);
    }
return NULL;
}
int main()
{
    pthread_t p1, p2;
    int max=10;
    pthread_create(&p1, NULL,&f_odd_function,&max);
    pthread_create(&p2, NULL,&f_even_function,&max);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);

    return 0;
}