#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node node;
struct node {
	int value;
	node* left;
	node* right;
	int balance;
	int lheight;
	int rheight;
};
int size;
node* head;

void init(node* tmp);
int max(int a, int b);
void update(node* cur);
void insert(int x, node* cur);
void add(int x);
node* pseudo_successor(node* cur);
node* parent(node* tmp);
void f(int x, node* cur, node* ar[], int* ind);
node* find(int x);
void __remove(int x, node* cur);
void delete(int x);
node* inorderkth(int k);
void range(node* cur, int l, int r, int* ar, int* ind);
node* rotate(node* z, node* y, node* x);
