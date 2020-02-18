#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct queue queue;
typedef struct node node;
struct queue {
	node* front;
	node* end;
	int size;
};
struct node {
	int value;
	node* nxt;
};

queue newQ();
bool isEmptyQ(queue q); // tests whether q is empty
queue delQ(queue q); // deletes the element from the front of the Queue returns the modified Queue
int front(queue q); // returns the element from the front of the Queue;
queue addQ(queue q , int e); // adds e to the rear of the Queue;
int lengthQ(queue q); // returns the length of the Queue
