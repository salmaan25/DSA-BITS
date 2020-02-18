/*******************************************************************
*           DSA Lab Test 2: Problem 2 (extras.c)
*   
*  Implement any support data structures in this file, if required.
* ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "extras.h"


heap createHeap(int n)
{ 
	heap h;
	h.size=0;
	
	//upper bound on size of heap
	h.a=(hnode*)malloc(sizeof(hnode)*(n+1));
	return h;
}
heap heapify(heap h,int t)
{
	int l=2*t+1;
	int r=2*t+2;
	int max;
	if(l<h.size)
	{
		max=h.a[t].w<h.a[l].w?l:t;
		if(r<h.size)
		{
			max=h.a[max].w<h.a[r].w?r:max;
		}
	}
	else
	 	max=t;
	if(max!=t)
	{
		hnode temp;
		temp=h.a[max];
		h.a[max]=h.a[t];
		h.a[t]=temp;
		heapify(h,max);
	}
	return h;
}	
heap insert(heap h,hnode n)
{
	h.a[h.size]=n;
	h.size++;
	int p=(h.size-2)/2;
	int cur=h.size-1;
	while(cur>0&&h.a[p].w<h.a[cur].w)
	{
		hnode temp=h.a[p];
		h.a[p]=h.a[cur];
		h.a[cur]=temp;
		cur=p;
		p=(p-1)/2;
	}
	return h;
}
		
	
heap deletemax(heap h)
{
	h.a[0]=h.a[h.size-1];
	h.size--;
	heapify(h,0);
	return h;
}
unsigned int max(heap h)
{
	return h.a[0].id;
}

int isEmpty(heap h)
{
	return !h.size;
}

// Write your code here.
