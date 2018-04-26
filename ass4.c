#include <stdio.h>
#include <pthread.h>
 
#define MAX_THREAD 10
#define MAX 1000
 
int a[MAX]; 
int sum[10] = { 0 };
int part = 0;
 int i;
 
 
void* sum_array(void* arg)
{
 
    int thread_part = part++;
 
    for ( i = thread_part * (MAX / 10); i < (thread_part + 1) * (MAX / 10); i++)
        sum[thread_part] += a[i];
}
 
int main()
{
 	int i;
 	int j;
 	int k;
	 for( i=0;i<MAX;i++)
	{
		a[i]=i;
	}
 	
    pthread_t threads[MAX_THREAD];
 
    // Here we create 10 threads
    for ( i = 0; i < MAX_THREAD; i++)
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL);
 
    // we join 10 threads as we wait for all 10 threads to complete
    
	for ( j = 0; j < MAX_THREAD; j++)
        pthread_join(threads[j], NULL);
 
    // adding sum of all 10 threads
   
    int total_sum = 0;
    for ( k = 0; k < MAX_THREAD; k++)
        total_sum += sum[k];
 
    printf("sum is %d\n",total_sum );
 
    return 0;
}
