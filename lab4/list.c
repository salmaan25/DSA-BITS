#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "cycle.h"

int space;
void* myalloc(int type) {
	type==1?(space += sizeof(head)):(space+=sizeof(node));
	return (type == 1?(malloc(sizeof(head))) : (malloc(sizeof(node))));
}
void myfree(node* n) {
	space -= sizeof(node);
	free(n);
}
head* createList(int sz) {
	head* h = (head*)myalloc(1);
	h->size = 0;
	h->ff = NULL;
	if(sz == 0)
		return h;
	node* n = (node*)myalloc(2);
	n->val = rand()%10000;
	n->nxt = NULL;
	node* cur = n;
	h->ff = cur;
	h->size++;
	for(int i = 1; i < sz; i++) {
		n = (node*)myalloc(2);
		cur->nxt = n;
		n->val = rand()%10000;
		n->nxt = NULL;
		cur = n;
		h->size++;
	}
	return h;
}
void printList(head* h) {
	if( testCyclic1(h)) {
		node* cur = h->ff;
		int flag = 0;
		while((flag == 0) || cur != h->ff) {
			if(cur == h->ff)
				flag = 1;
			printf("%d ", cur->val);
			cur = cur->nxt;
		}
		printf("\n");
		return;
	}
	node* n = h->ff;
	printf("%d\n", h->size);
	while(n != NULL) {
		printf("%d ", n->val);
		n = n->nxt;
	}
	printf("\n");
}
void printSpace() {
	printf("%d\n", space);
}
void createCycle(head* h, int sz) {
	if(rand()%2 == 0) {
		// printf("in\n");
		int n_ct = rand()%sz;
		// printf("cycle at %d and size is %d\n", n_ct, sz);
		node* cur = h->ff;
		for(int i = 0; i < sz; i++) {
			if(i == n_ct) {
				node* lst = h->ff;
				while(lst != NULL) {
					if(lst->nxt == NULL)
						break;
					lst = lst->nxt;
				}
				lst->nxt = cur;
				return;
			}
			cur = cur->nxt;
		}
	}
}
