/*******************************************************************
*           DSA Lab Test 2: Problem 2 (extras.h)
*   
*  Interface any support data structures in this file, if required.
* ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "graph.h"

#ifndef EXTRAS_H_INCLUDED
#define EXTRAS_H_INCLUDED


// Write your code here.
struct hnode
{
	unsigned int id;
	int w;
};
typedef struct hnode hnode;

struct heap
{
	int size;
	hnode* a;
};
typedef struct heap heap;

heap createHeap(int n);
heap heapify(heap h,int t);
heap insert(heap h,hnode n);
heap deletemax(heap h);
unsigned int max(heap h);
int isEmpty(heap h);


#endif
