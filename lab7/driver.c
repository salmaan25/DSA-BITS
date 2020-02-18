#include "sort.h"

int main(void) {
	recCt = 0;
	node* n = readFile("20.txt");
	printf("done\n");
	// printList(n);
	// insertionSort(n, recCt);
	printf("done\n");
	// printList(n);
	// printf("%d\n", recCt);
	iterQuickSort(n, recCt, 5);
	printList(n);
	return 0;
}