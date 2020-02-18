#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cd.h"

int sz = 0;

cd* init() {
	sz += 3;
	return (cd*)(malloc(3*sizeof(cd)));
}
cd* insert(char* str, int ind, cd* h) {
	cd* he;
	if(sz <= ind) {
		he = (cd*)realloc(h, (sz+3)*sizeof(cd));
		sz += 3;
	}
	else
		he = h;
	/*IMPORTANT*/
	char* pch = strtok(str, ",");
	int st = 0;
	while(pch != NULL) {
		//(char)34 converts 34 to the corresponding ascii value which is " here
		if(st == 0) {
			for(int i = 1; i < 17; i++)
				he[ind].cn[i-1] = (int)(str[i]-'0');
		}
		if(st == 1) {
			strcpy(he[ind].bc, pch);
		}
		if(st == 2) {
			he[ind].ed[0] = (int)(pch[0]-'0'); he[ind].ed[1] = (int)(pch[1]-'0');
			he[ind].ed[2] = (int)(pch[3]-'0'); he[ind].ed[3] = (int)(pch[4]-'0');
			he[ind].ed[4] = (int)(pch[5]-'0'); he[ind].ed[5] = (int)(pch[6]-'0');
		}
		if(st == 3) {
			strcpy(he[ind].fn, pch);
		}
		if(st == 4) {
			strcpy(he[ind].ln, pch);
			he[ind].ln[strlen(pch)-1] = '\0';
		}
		/*IMPORTANT*/
		pch = strtok(NULL, ",");
		st++;
	}
	return he;
}
void printList(cd* h, int sz) {
	for(int i = 0; i < sz; i++) {
		for(int j = 0; j < 16; j++)
			printf("%d", h[i].cn[j]);
		printf(" ");
		printf("%s ", h[i].bc);
		for(int j = 0; j < 6; j++) {
			if(j == 2)
				printf("-");
			printf("%d", h[i].ed[j]);
		}
		printf(" %s ", h[i].fn);
		printf("%s\n", h[i].ln);
	}
}
int cmp(cd a, cd b) {
	for(int i = 0; i < 16; i++) {
		if(a.cn[i] < b.cn[i])
			return -1;
		if(a.cn[i] > b.cn[i])
			return 1;
	}
	return 0;
}
void insertInOrder(cd* h, int st) {
	for(int i = 0; i < st; i++) {
		if(cmp(h[i], h[st]) >= 0) {
			cd tmp = h[st];
			for(int j = st; j > i; j--)
				h[j] = h[j-1];
			h[i] = tmp;
			break;
		}
	}
}
void insertionSort(cd* h, int st, int sz) {
	if(st == 0) {
		return;
	}
	else {
		insertionSort(h, st-1, sz);
		insertInOrder(h, st);
	}
}