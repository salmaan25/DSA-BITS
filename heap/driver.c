#include "heap.h"

int main(void) {
	hp_sz = 1;
	int ar[] = {9, 8 ,7, 6, 1, 5};
	int* hp = heapify(ar, 6);
	printHeap(hp);
	int ans = pop(hp);
	printf("%d\n", ans);
	printHeap(hp);
	ans = pop(hp);
	printf("%d\n", ans);
	printHeap(hp);
	heapsort(ar, 6);
	for(int i = 0; i < 6; i++)
		printf("%d ", ar[i]);
	printf("\n");
	return 0;
}