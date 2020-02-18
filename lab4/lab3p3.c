#include <stdio.h>
#include <stdlib.h> 
#include<time.h> 
// #include <stdlib.h>
#include <sys/time.h>
#include "list.h"
#include <stdbool.h>
#include "cycle.h"
#define N 1000000

int main(void) {
	srand(time(0));
	struct timeval t1, t2;
	double elapsedTime;
	// start timer
	gettimeofday(&t1, NULL);

	head* h = createList(N);
	printSpace();	
	// printList(h);
	if(testCyclic1(h))
		printf("cyclic\n");
	else
		printf("non cyclic\n");
	createCycle(h, N);
	if(testCyclic1(h))
		printf("cyclic\n");
	else
		printf("non cyclic\n");
	// if(testCyclic2(h))
	// 	printf("cyclic\n");
	// else
	// 	printf("non cyclic\n");
	// stop timer
	makeCircularList(h);
	printSpace();
	// printList(h);
 	gettimeofday(&t2, NULL);
 	// compute and print the elapsed time in millisec
 	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
 	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
 	printf("Total time is %lf ms.\n", elapsedTime);
	return 0;
}