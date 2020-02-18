//gcc –c linkedlist.c
//gcc –c driver.c
//gcc –o exe linkedlist.o driver.o
//./exe sampleInput.txt

#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include <stdlib.h>
#include "multiq.h"

int main(void) {
	/*queue q = newQ();
	q = addQ(q, 2);
	q = addQ(q, 4);
	q = addQ(q, 1);
	q = addQ(q, 6);
	q = addQ(q, 8);
	printf("%d\n", lengthQ(q));
	q = addQ(q, 10);
	printf("%d\n", lengthQ(q));
	printf("%d\n", front(q));
	q = delQ(q);
	printf("%d\n", front(q));
	while(!isEmptyQ(q)) {
		printf("%d\n", front(q));
		q = delQ(q);
	}*/
	/*multiQ mq =  createMQ(4);
	task t;
	t.value = 3;
	t.priority = 1;
	mq = addMQ(mq, t);
	t.value = 4;
	t.priority = 2;
	mq = addMQ(mq, t);
	t.value = 5;
	t.priority = 2;
	mq = addMQ(mq, t);
	t.value = 6;
	t.priority = 2;
	mq = addMQ(mq, t);
	t.value = 6;
	t.priority = 3;
	mq = addMQ(mq, t);
	printf("%d\n", sizeMQ(mq));
	
	printf("%d\n", nextMQ(mq).size);
	
	mq = delNextMQ(mq);
	printf("%d\n", sizeMQ(mq));
	
	printf("%d\n", sizeMQbyPriority(mq, 2));*/
	multiQ mq =  createMQ(10000);
	char tmp[100];
	FILE* f = fopen("input10000.txt", "r");
	int rd = 0;
	//while(fscanf(f, "%s", tmp)) {
	while(rd < 10000) {
		rd++;
		fscanf(f, "%s", tmp);
		char name[100];
		int szn = 0;
		char pr[100];
		int szpr = 0, ch = 0;
		int i = 0;
		while(tmp[i] != '\0') {
			if(tmp[i] == ',')
				ch = 1-ch;
			else {
				if(ch == 0) {
					name[szn] = tmp[i];
					szn++;
				}
				else {
					pr[szpr] = tmp[i];
					szpr++;
				}
			}
			i++;
		}
		name[szn] = '\0'; pr[szpr] = '\0';
		int nm = atoi(name); int prr = atoi(pr);
		printf("%d  %d\n", nm, prr);
		task t;
		t.value = nm;
		t.priority = prr;
		mq = addMQ(mq, t);
	}
	printf("%d\n", sizeMQ(mq));
	
	printf("%d\n", nextMQ(mq).size);
	printf("%d\n", mq.max);
	mq = delNextMQ(mq);
	printf("%d\n", sizeMQ(mq));
	//printf("dsd %d\n", mq.max);
	printf("%d\n", sizeMQbyPriority(mq, 2));
	//printf("dsd %d\n", mq.max);
	printf("%d\n", sizeMQbyPriority(mq, mq.max));
	printf("%d\n", mq.max);
	return 0;
}







