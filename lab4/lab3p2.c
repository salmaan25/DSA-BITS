#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
int space; 
int M = 20;
int* myalloc(int sz) {
	int* add = (int*)malloc(sz*sizeof(int));
	space += sz*sizeof(int);
	return add;
}
void myfree(int* st, int sz) {
	space -= sz*sizeof(int);
	free(st);
}

int main(void) {
	// int* t1 = myalloc(20);
	// printf("%d\n", space);
	// int* t2 = myalloc(30);
	// printf("%d\n", space);
	// int* t3 = myalloc(5);
	// printf("%d\n", space);
	// int* t4 = myalloc(25);
	// printf("%d\n", space);
	// myfree(t3, 5);
	// printf("%d\n", space);
	// myfree(t1, 20);
	// printf("%d\n", space);
	int* tmp = myalloc(M);
	int ct = 0;
	while(tmp != NULL) {
		ct++;
		// m/yfree(tmp, M);
		printf("%u  %u\n", (unsigned int)((uintptr_t)&tmp[0]), (unsigned int)((uintptr_t)&tmp[M-1]));
		tmp = myalloc(M);
	}
	printf("%d\n", ct);
	return 0;
}