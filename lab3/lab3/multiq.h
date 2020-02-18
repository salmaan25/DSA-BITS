#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//#include "queue.h"


typedef struct multiQ multiQ;
typedef struct task task;
struct multiQ {
	queue* q;
	int size;
	int length;
	int max;
};
struct task {
	int value;
	int priority;
};
multiQ createMQ(int num); // creates a list of num Queues, each of which is empty.
multiQ addMQ(multiQ mq, task t); // adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.
queue nextMQ(multiQ mq); // returns the front of the non-empty Queue in mq with the highest priority.
multiQ delNextMQ(multiQ mq); // deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ
bool isEmptyMQ(multiQ mq); // tests whether all the Queues in mq are empty
int sizeMQ(multiQ mq); // returns the total number of items in the MultiQ
int sizeMQbyPriority(multiQ mq, int p); //returns the number of items in mq with the priority p.
queue getQueueFromMQ(multiQ mq, int p); //returns the Queue with priority p.
