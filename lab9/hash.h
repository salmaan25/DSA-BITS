#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node node;
struct node {
	int count;
	int index;
	node* nxt;
};
typedef struct record record;
struct record {
	int count;
	int index;
};
int wct, bn, ts, elcount, insertcost, querycost;
char** book;
node* table;
int min(int a, int b);
void readFile();
int asciiSum(char* str);
int hash(char* str, int baseNum, int tableSize);
int collCount(int baseNum, int tableSize);
bool checkPrime(int n);
void findPrimes(int* p, int tableSize);
int profile();
void create();
void insert(char* str, int ind);
int insertAll();
record lookup(char* str);
int lookupAll(int m);
int profiling();
int cleanup();