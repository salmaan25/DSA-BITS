#include "tree.h"

int main(void) {
	int type = 0;
	FILE* fp = fopen("input.txt", "r");
	while(fscanf(fp, "%d", &type) == 1) {
		if(type == 1) {
			readdata(fp);
		}
		else if(type == -1)
			break;
		else if(type == 3)
			find_lca(fp);
		else
			lookup(fp);
	}
	char st[100];
	st[0] = '\0';
	// printdata(head->nxtc, st);
	return 0;
}
