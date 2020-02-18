#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include <stdlib.h>


queue newQ() {
	queue* q = (queue*)malloc(sizeof(queue));
	q->front = NULL;
	q->end = NULL;
	q->size = 0;
	return *q;
}
bool isEmptyQ(queue q) {
	return (q.size==0?true:false);
} // tests whether q is empty
queue delQ(queue q) {
	if(isEmptyQ(q))
		return q;
	if(q.size == 1) {
		q.front = NULL; q.end = NULL; q.size = 0;
		return q;
	}
	q.front = q.front->nxt;
	q.size--;
	return q;
} // deletes the element from the front of the Queue returns the modified Queue
int front(queue q){ 
	if(isEmptyQ(q))
		return -100;	
	return q.front->value;
} // returns the element from the front of the Queue;
queue addQ(queue q , int e) {
	node* n = (node*)malloc(sizeof(node));
	n->value = e;
	if(q.size == 0) {
		q.front = n;
		q.end = n;
		q.size++;
		return q;
	}
	q.end->nxt = n;
	q.end = n;
	q.size++;
	return q;
} // adds e to the rear of the Queue;
int lengthQ(queue q) {
	return q.size;
} // returns the length of the Queue



