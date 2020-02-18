#include <stdbool.h>
#include <stdio.h>
#include "list.h"
bool testCyclic1(head* h) {
	node* hare = h->ff;
	node* tor = h->ff;
	int flag = 1;
	while((flag == 1 && hare == tor) || (flag == 0 && hare != tor)) {
		if(flag == 1)
			flag = 0;
		if(hare->nxt == NULL)
			return false;
		if(hare->nxt->nxt == NULL)
			return false;
		if(tor->nxt == NULL)
			return false;
		hare = hare->nxt->nxt;
		tor = tor->nxt;
	}
	return true;
}
bool testCyclic2(head* h) {
	node* st = h->ff;
	if(st->nxt == NULL)
		return false;
	node* cur= st->nxt;
	node* prev = st;
	while(cur != st) {
		if(cur->nxt == NULL)
			return false;
		node* tmp = cur->nxt;
		cur->nxt = prev;
		prev = cur;
		cur = tmp;
	}
	return true;
}

// from testcyclic1 we know one of the nodes of the cycle (say cyc) now start from head and store adresses in array such that cyc comes twice and the second time at the end now from the two
// positions of cyc in array (say pos1 and pos2) start moving backwards and compare the values if they are same keep moving backwards else stop. now pos1+1 is the node number of the first element of 
// the cycle in the linked list. now iterate through the linked list and remove every other element before it. The new linked list is circular.
void makeCircularList(head* h) {
	if(!testCyclic1(h)) {
		//simple just point last node to first
		return;
	}
	node* hare = h->ff;
	node* tor = h->ff;
	int flag = 1;
	while((flag == 1 && hare == tor) || (flag == 0 && hare != tor)) {
		if(flag == 1)
			flag = 0;
		hare = hare->nxt->nxt;
		tor = tor->nxt;
	}
	node* cyc = tor;
	int ct = 0;
	int sz = 0;
	node* cur = h->ff;
	while(ct < 2) {
		if(cur == cyc)
			ct++;
		sz++;
		cur = cur->nxt;
	}
	ct = 0;
	unsigned int add[sz];
	cur = h->ff;
	sz = 0; int pos1 = 0, pos2 = 0;
	while(ct < 2) {
		if(cur == cyc) {
			if(ct == 0)
				pos1 = sz;
			if(ct == 1)
				pos2 = sz;
			ct++;
		}
		add[sz] = (unsigned int)(cur);
		sz++;
		cur = cur->nxt;
	}
	while(pos1 >= 0 && pos2 >= 0 && add[pos1] == add[pos2]) {
		pos1--;
		pos2--;
	}
	pos1++;
	sz = 0;
	cur = h->ff;
	node* prev = cur;
	while(sz < pos1) {
		prev = cur;
		cur = cur->nxt;
		myfree(prev);
		sz++;
	}
	h->ff = cur;
}