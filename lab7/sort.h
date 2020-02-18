#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int recCt;
typedef struct node node;
struct node {
	char* name;
	int empID;
};
typedef struct snode snode;
typedef struct stack stack;
struct snode {
	int lo, hi;
};
struct stack {
	snode* v;
	int size;
};
void push(int lo, int hi, stack* s);
snode  pop(stack* s);
node* readFile(char* s);
void printList(node* n);
int partition(node* n, int lo, int hi, int piv_ind);
void iterQuickSort(node* n, int sz, int S);
void insertionSort(node* n, int sz);
