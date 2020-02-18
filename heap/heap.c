#include "heap.h"

int* heapify(int* ar, int sz) {
	int* hp = (int *)malloc((sz+1)*sizeof(int));
	hp[1] = ar[0];
	hp_sz++;
	int ct;
	for(int i = 2; i <= sz; i++) {
		hp[i] = ar[i-1];
		push(hp, i);
	}
	hp_sz = sz;
	return hp;
}
int left(int* hp, int p) {
	return 2*p>hp_sz?-1:2*p;
}
int right(int* hp, int p) {
	return 2*p+1>hp_sz?-1:2*p+1;
}
int pop(int* hp) {
	int ret = hp[1];
	hp[1] = hp[hp_sz];
	hp_sz--;
	removex(hp, 1);
	return ret;	
}
void removex(int* hp, int p) {
	if(left(hp, p) == -1)
		return;
	if(right(hp, p) == -1) {
		if(hp[p] < hp[left(hp, p)]) {
			int tmp = hp[left(hp, p)];
			hp[left(hp, p)] = hp[p];
			hp[p] = tmp;
			return removex(hp, left(hp, p));
		}
	}
	else {
		int mx_ind = hp[left(hp, p)]>=hp[right(hp, p)]?left(hp, p):right(hp, p);
		int tmp = hp[mx_ind];	
		hp[mx_ind] = hp[p];
		hp[p] = tmp;
		return removex(hp, mx_ind);
	}
}
void insert(int *hp, int ele) {
	hp[hp_sz+1] = ele;
	push(hp, hp_sz+1);
	hp_sz++;
}
void push(int* hp, int ind) {
	if(ind/2 == 0)
		return;
	if(hp[ind/2] < hp[ind]) {
		int tmp = hp[ind/2];
		hp[ind/2] = hp[ind];
		hp[ind] = tmp;
		push(hp, ind/2);
	}
	return;
}
void printHeap(int* hp) {
	for(int i = 1; i <= hp_sz; i++)
		printf("%d ", hp[i]);
	printf("\n");
}

bool empty(int* hp) {
	return hp_sz==0?true:false;
}
void heapsort(int* ar, int sz) {
	int * hp = heapify(ar, sz);
	int ind = sz-1;
	while(!empty(hp)) {
		ar[ind] = pop(hp);
		ind--;
	}
}