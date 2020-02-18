#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include "cd.h"
int main(void) {
	FILE *fp1 = fopen("10.txt", "r");
	FILE* fp2 = fopen("output.txt", "w");
	if(fp1 == NULL || fp2 == NULL) {
		printf("ERROR\n");
		exit(1);
	}
	char buffer[100];
	int ind = 0;
	cd* h;
	h = init();
	while(fscanf(fp1, "%s", buffer) == 1) {
		h = insert(buffer, ind, h);
		ind++;
	}
	printList(h, ind);
	insertionSort(h, ind-1, ind);
	printList(h, ind);
	// printf("%p %p %d\n", &ad1, &ad2, -1*(unsigned int)((uintptr_t)&ad1)+(unsigned int)(uintptr_t)&ad2);
	return 0;
}