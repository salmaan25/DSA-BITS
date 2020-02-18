#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node node;
struct node {
	char name[100];
	node* nxtc;
	node* nxts;
	int isleaf;
};
node* head;
node* insert(node* cur, char* n);
void readdata(FILE* fp);
void lookup(FILE* fp);
void printdata(node* cur, char st[]);
char** extract(char* str, int* sz);
node* lc(node* cur, char* str);
char* lca(char* s1, char* s2);
void find_lca(FILE* fp);
