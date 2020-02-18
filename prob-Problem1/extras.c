/*******************************************************************
*           DSA Lab Test 2: Problem 1 (extras.c)
*   
*  Implement any support data structures in this file, if required.
* ******************************************************************/
#include "extras.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>

stack createStack()
{
	stack s;
	s.a=NULL;
	s.size=0;
	return s;
}

stack push(stack s,tree t)
{
	if(t==NULL)
		return s;
	node n;
	n.p=t;
	if(isEmpty(s))
	{
		s.a=(node*)malloc(sizeof(node));
		s.a[0]=n;
		s.size++;
	}
	else
	{
		s.a=(node*)realloc(s.a,(s.size+1)*sizeof(node));
		s.size++;
		s.a[s.size-1]=n;
	}
	return s;
}

stack pop(stack s)
{
	if(!isEmpty(s))
	{
		s.a=(node*)realloc(s.a,(s.size-1)*sizeof(node));
		s.size--;
	}
	return s;
}

tree top(stack s)
{
	if(!isEmpty(s))
		return s.a[s.size-1].p;
	else
		return NULL;
}
int isEmpty(stack s)
{
	if(s.size==0)
		return 1;
	return 0;
}
	
// Write your code here.
