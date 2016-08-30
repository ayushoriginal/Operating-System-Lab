
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//Use Global variables

typedef struct datastruct
{
	int size;
	int *values;
}datastruct;
void *max_func(void *ptr)
{
	datastruct * copy;
	copy = (datastruct *) ptr;
	int sz = copy->size;
	int i;
	int max = copy->values[0];
	for(i = 1; i < sz; i++)
	{
		if(max < copy->values[i])
			max = copy->values[i];
	}
	pthread_exit(max);
	return NULL;
}
void *min_func(void *ptr)
{
	datastruct * copy;
	copy = (datastruct *) ptr;
	int sz = copy->size;
	int i;
	int min = (copy->values[0]);
	for(i = 1; i < sz; i++)
	{
		if(min > (copy->values[i]))
			min = (copy->values[i]);
	}
	pthread_exit(min);
	return NULL;

}
void *avg_func(void *ptr)
{
	datastruct * copy;
	copy = (datastruct *) ptr;
	int sz = copy->size;
	int i;
	for(i = 0; i < sz; i++)
		avg += (copy->values[i]);
	int avg = (int)(avg / sz);
	pthread_exit(avg);
	return NULL;

}




int main()
{
	int *min, *max, *avg;
	printf("\nEnter the number of integers in your array\n\n");
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0; i<n ;i++)
	{
		scanf("%d",&arr[i]); 				
		copy[i] = arr[i];	
	}

	pthread_t thread1, thread2, thread3;
	const char *message1 = "This is Thread 1";
	const char *message2 = "This is Thread 2";
	const char *message3 = "This is Thread 3";

	int t1, t2, t3;
	printf("Running: %s\n\n");
        int *ptr = arr;
	datastruct ds = {n, ptr};

	t1 = pthread_create(&thread1, NULL, (void *) avg_func, (void *) &ds);
	
	t2 = pthread_create(&thread2, NULL, (void *) min_func, (void *) &ds);

	
	t3 = pthread_create(&thread3, NULL, (void *) max_func, (void *) &ds);

	printf("pthread_create() for Thread 1 returns: %d\n",t1);
	printf("pthread_create() for Thread 2 returns: %d\n",t2);
	printf("pthread_create() for Thread 3 returns: %d\n\n",t3);
	/* Wait till threads are complete before main continues. */
	pthread_join(thread1, &avg);
	pthread_join(thread2, &min);
	pthread_join(thread3, &max);
	printf("The average: %g\n", avg);
	printf("The minimum: %d\n", min);
	printf("The maximum: %d\n", max);
	return 0;
	

}


	
