#include <stdio.h>
#include <pthread.h>
 
#define Big_thread 10
#define MAX 1000
 
int a[MAX]; 
int sum[10] = { 0 };
int part = 0;
 int i; 

 void* sum_array(void* arg)
{
 
    int T_piece = part++;
 
    for ( i = T_piece * (MAX / 10); i < (T_piece + 1) * (MAX / 10); i++)
        sum[T_piece] += a[i];
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
 	
    pthread_t threads[Big_thread];
 
    // Here we create 10 threads
    for ( i = 0; i < Big_thread; i++)
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL);
 
    // we join 10 threads as we wait for all 10 threads to complete
    
	for ( j = 0; j < Big_thread; j++)
        pthread_join(threads[j], NULL);
 
    // adding sum of all 10 threads
   
    int total_sum = 0;
    for ( k = 0; k < Big_thread; k++)
        total_sum += sum[k];
 
    printf("The Total Sum is %d\n",total_sum );
 
    return 0;
}
