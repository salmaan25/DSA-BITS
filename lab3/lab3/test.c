#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include <stdlib.h>


typedef struct s1 s1;
typedef struct s2 s2;
struct s1 {
	int* ar;
};
struct s2 {
	s1* pnt;
};
int main(void) {
	s2* st = (s2*)malloc(sizeof(s2));
	st->pnt = (s1*)malloc(sizeof(s1));
	st->pnt->ar = (int*)malloc(4 * sizeof(int));
	st->pnt->ar[0] = 1;
	st->pnt->ar[1] = 2;
	st->pnt->ar[2] = 3;
	st->pnt->ar[3] = 4;
	for(int i = 0; i < 4; i++)
		printf("%d ", st->pnt->ar[i]);
	printf("\n");
	return 0;
}
