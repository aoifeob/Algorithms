#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 4

double width, midpoint, area = 0.0;
int numIntervals;
pthread_mutex_t area_mutex = PTHREAD_MUTEX_INITIALIZER;
int interval, iCount;
double myArea = 0.0, result;

void *PrintHello(void *threadID){
	printf("\n: Hello World!\n");
	pthread_exit(NULL);
}

int main(int argc, const char *argv[]){
	pthread_t threads[NUM_THREADS];
	int rc, t;

	//create threads
	for (t=0;t<NUM_THREADS;t++){
		printf("Creating thread %d\n",t);
		rc = pthread_create(&threads[t], NULL, PrintHello,(void *) &t);
		if (rc){
			printf("ERROR return code from pthread_create(): %d\n", rc);
			exit(-1);
		}
	}

	//wait for threads to exit 
	for(t=0;t<NUM_THREADS;t++){
		pthread_join(threads[t],NULL);
	}
	return(0);
}
