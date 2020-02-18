#include "bst.h"

int main(void) {
	size = 0;
	add(6);
	add(10);
	add(2);
	add(4);
	add(3);
	node* x = find(3);
	if(x != NULL)
		printf("found\n");
	else
		printf("not found\n");
	// delete(3);
	delete(4);
	delete(10);
	// delete(6);
	x = find(3);
	if(x != NULL)
		printf("found\n");
	else
		printf("not found\n");
	// printf("size = %d\n", size);
	x = inorderkth(3);
	if(x != NULL)
		printf("%d\n", x->value);
	int ar[100]; int ind = 0;
	range(head, 0, 7, ar, &ind);
	for(int i = 0; i < ind; i++)
		printf("%d ", ar[i]);
	printf("\n");
	return 0;
}