#include "sort.h"

void push(int lo, int hi, stack* s) {
	// printf("push %d %d\n", );
	s->v[s->size].lo = lo;
	s->v[s->size].hi = hi;
	s->size++;
}

snode pop(stack* s) {
	snode sn;
	sn.lo = s->v[s->size-1].lo;
	sn.hi = s->v[s->size-1].hi;
	s->size--;
	return sn;
}
void swap(node* n1, node* n2) {
	node tmp;
	tmp.name = (char *)malloc(1+strlen(n1->name));
	strcpy(tmp.name, n1->name);
	tmp.empID = n1->empID;
	strcpy(n1->name, n2->name);
	n1->empID = n2->empID;
	strcpy(n2->name, tmp.name);
	n2->empID = tmp.empID;
}
int partition(node* n, int lo, int hi, int piv_ind) {
	swap(&n[lo], &n[piv_ind]);
	int i = lo+1;
	for(int j = lo+1; j <= hi; j++) {
		if(n[j].empID < n[lo].empID) {
			swap(&n[i], &n[j]);
			i++;
		}
	}
	swap(&n[lo], &n[i-1]);
	return i-1;
}
void iterQuickSort(node* n, int sz, int S) {
	stack st;
	st.size = 0;
	st.v = (snode*)malloc(sz*sizeof(snode));
	push(0 ,sz-1, &st);
	// st.push(0, sz-1)
	while(st.size > 0) {
		snode p = pop(&st);
		//piv_ind randomly generate
		int piv_ind = rand()%(p.hi-p.lo) + p.lo;
		// printf("%d %d %d\n", p.lo, p.hi, piv_ind);
		int piv = partition(n, p.lo, p.hi, piv_ind);
		// printList(n);
		if(p.lo < piv-1)
			push(p.lo, piv-1, &st);
		if(p.hi > piv+1)
			push(piv+1, p.hi, &st);
	}
}
void insertionSort(node* n, int sz) {
	for(int i = 1; i < sz; i++) {
		int ind = -1;
		for(int j = 0; j < i; j++) {
			if(n[j].empID > n[i].empID) {
				ind = j;
				break;
			}
		}
		node sw;
		sw.name = malloc(1+strlen(n[i].name));
		strcpy(sw.name, n[i].name);
		sw.empID = n[i].empID;
		if(ind != -1) {
			for(int j = i; j > ind; j--) {
				n[j] = n[j-1];
			}
			n[ind] = sw;
			strcpy(n[ind].name, sw.name);
			n[ind].empID = sw.empID;
		}
	}
}

node* readFile(char* fname) {
	node* n = malloc(10*sizeof(node));
	int sz = 10;
	FILE* fp = fopen(fname, "r");
	char buf[20];
	while(fscanf(fp, "%s", buf) == 1) {
		int empID;
		fscanf(fp, "%d", &empID);
		// printf("%s %d\n", buf, empID);
		if(sz == recCt) {
			node* tmp = realloc(n, 10*sizeof(node)+sz*sizeof(node));
			sz += 10;
			n = tmp;
		}
		n[recCt].name = malloc(1+strlen(buf));
		strcpy(n[recCt].name, buf);
		n[recCt].empID = empID;
		recCt++;
	}
	return n;
}
void printList(node* n) {
	FILE* fp = fopen("output.txt", "w");
	for(int i = 0; i < recCt; i++)
		fprintf(fp, "%s %d\n", n[i].name, n[i].empID);
		// printf("%s %d\n", n[i].name, n[i].empID);
}