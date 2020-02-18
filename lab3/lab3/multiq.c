#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include "multiq.h"
#include <stdlib.h>

//if real priority is to be returned the return priority+1 i.e index+1;
multiQ createMQ(int num) {
	multiQ* m = (multiQ*)malloc(sizeof(multiQ));
	m->q = (queue*)malloc(num*sizeof(queue));
	m->size = 0;
	m->length = num;
	m->max = -100;
	for(int i = 0; i < num; i++)
		m->q[i] = newQ();
	return *m;
} // creates a list of num Queues, each of which is empty.
multiQ addMQ(multiQ mq, task t) {
	mq.q[t.priority-1] = addQ(mq.q[t.priority-1], t.value);
	//(t.value>mq.max)?mq.max=t.priority:mq.max=mq.max;
	if(t.priority-1 > mq.max)
		mq.max = t.priority-1;
	mq.size++;
	return mq;
} // adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.
queue nextMQ(multiQ mq) {
	return mq.q[mq.max];
} // returns the front of the non-empty Queue in mq with the highest priority.
multiQ delNextMQ(multiQ mq) {
	//int ret = 0;
	if(mq.q[mq.max].size == 0)
		return mq;
	mq.q[mq.max] = delQ(mq.q[mq.max]);
	mq.size--;
	for(int i = mq.length-1; i >= 0; i--) {
		if(mq.q[i].size > 0) {
			mq.max = i;
			break;
		}
	}
	return mq;
} // deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ
bool isEmptyMQ(multiQ mq) {
	return mq.size==0?true:false;
} // tests whether all the Queues in mq are empty
int sizeMQ(multiQ mq) {
	return mq.size;
} // returns the total number of items in the MultiQ
int sizeMQbyPriority(multiQ mq, int p) {
	return mq.q[p-1].size;
} //returns the number of items in mq with the priority p.
queue getQueueFromMQ(multiQ mq, int p) {
	return mq.q[p];
}//returns the Queue with priority p.



