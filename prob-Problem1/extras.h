/*******************************************************************
*           DSA Lab Test 2: Problem 1 (extras.h)
*   
*  Implement any support data structures in this file, if required.
* ******************************************************************/

#include "tree.h"
#ifndef EXTRAS_H_INCLUDED
#define EXTRAS_H_INCLUDED

// Write your code here.

struct node
{
	tree p;
};
typedef struct node node;

struct stack
{
	node *a;
	int size;
};
typedef struct stack stack;

stack createStack();
stack push(stack,tree);
stack pop(stack);
tree top(stack);
int isEmpty(stack);
	

#endif // EXTRAS_H_INCLUDED
