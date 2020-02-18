#include "hash.h"

int min(int a, int b) {
	return a<=b?a:b;
}
void readFile() {
	int len = 0, ct = 0;
	FILE* fp1 = fopen("aliceinwonderland.txt", "r");
	char buffer[100];
	while(fscanf(fp1, "%s", buffer) == 1) {
		int flag = 0;
		for(int i = 0; i < strlen(buffer); i++) {
			if((int)buffer[i] < (int)'A' || (int)buffer[i] > (int)'z' || ((int)buffer[i] > (int)'Z' && (int)buffer[i] < (int)'a')) {
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			ct++;
	}
	fclose(fp1);
	book = (char**)malloc(sizeof(char*)*ct);
	wct = ct;
	FILE* fp = fopen("aliceinwonderland.txt", "r");
	while(fscanf(fp, "%s", buffer) == 1) {
		int flag = 0;
		for(int i = 0; i < strlen(buffer); i++) {
			if((int)buffer[i] < (int)'A' || (int)buffer[i] > (int)'z' || ((int)buffer[i] > (int)'Z' && (int)buffer[i] < (int)'a')) {
				flag = 1;
				break;
			}
		}
		if(flag != 1) {
			book[len] = (char*)malloc(strlen(buffer)+1);
			strcpy(book[len], buffer);
			len++;
		}
	}
	fclose(fp);
}

int asciiSum(char* str) {
	int ret = 0;
	for(int i = 0; i < strlen(str); i++)
		ret += (int)str[i];
	return ret;
}
int hash(char* str, int baseNum, int tableSize) {
	return (asciiSum(str)%baseNum)%tableSize;
}
int collCount(int baseNum, int tableSize) {
	int ar[wct];
	for(int i = 0; i < wct; i++)
		ar[i] = 0;
	int ret = 0;
	for(int i = 0; i < wct; i++) {
		int ind = hash(book[i], baseNum, tableSize);
		if(ar[ind] == 1)
			ret++;
		else
			ar[ind] = 1;
	}
	return ret;
}
bool checkPrime(int n) {
	for(int i = 2; i*i < n; i++) {
		if(n%i == 0)
			return false;
	}
	return true;
}
void findPrimes(int* p, int tableSize){
	int cur = tableSize+1;
	int ct = 0;
	while(ct != 3) {
		if(checkPrime(cur)) {
			p[ct] = cur;
			ct++;
		}
		cur++;
	}
	cur = 1000*tableSize+1;
	while(ct != 6) {
		if(checkPrime(cur)) {
			p[ct] = cur;
			ct++;
		}
		cur++;
	}
}
int profile() {
	int mn = 1000000000, mnbn = 0, mnts = 0;
	int ar[] = {5000, 50000, 500000};
	for(int i = 0; i < 3; i++) {
		int p[6];
		findPrimes(p, ar[i]);
		for(int j = 0; j < 6; j++) {
			if(mn > collCount(p[j], ar[i])) {
				mn = collCount(p[j], ar[i]);
				mnbn = p[j];
				mnts = ar[i];
			}
		}
	}
	bn = mnbn;
	ts = mnts;
	return mn;
}
void create() {
	table = (node*)malloc(sizeof(node)*ts);
	for(int i = 0; i < ts; i++) {
		table[i].count=0;
		table[i].index=-1;
		table[i].nxt=NULL;
	}
	elcount = 0; insertcost = 0; querycost = 0;
}
void insert(char* str, int ind) {
	int in = hash(str, bn, ts);
	node* st = table[in].nxt;
	if(st == NULL) {
		elcount++;
		node* nd = (node*)malloc(sizeof(node));
		nd->count = 1;
		nd->index = ind;
		nd->nxt = NULL;
		table[in].nxt = nd;
		return;
	}
	int cost = 0;
	while(st != NULL) {
		if(strcmp(book[st->index], str) == 0) {
			st->count++;
			return;
		}
		cost++;
		if(st->nxt == NULL)
			break;
		st = st->nxt;
	}
	elcount++;
	insertcost += cost;
	node* nd = (node*)malloc(sizeof(node));
	nd->count = 1;
	nd->index = ind;
	nd->nxt = NULL;
	st->nxt = nd;
}
int insertAll() {
	insertcost = 0;
	for(int i = 0; i < wct; i++)
		insert(book[i], i);
	return insertcost;
}
record lookup(char* str) {
	int ind = hash(str, bn, ts);
	node* it = table[ind].nxt;
	record rec;
	rec.count = 0; rec.index = -1;
	while(it != NULL) {
		if(strcmp(str, book[it->index]) == 0) {
			rec.count = it->count;
			rec.index = it->index;
			return rec;
		}
		querycost++;
		it = it->nxt;
	}
	return rec;
}
int lookupAll(int m) {
	querycost = 0;
	for(int i = 0; i < (m*wct)/100; i++)
		lookup(book[i%wct]);
	return querycost;
}
int profiling() {
	int m = 10;
	while(m <= 200) {
		printf("%d\n", lookupAll(m));
		if(lookupAll(m) > insertcost)
			break;
		m += 10;
	}
	return m;
}
int cleanup() {
	FILE* fp = fopen("stopwords.txt", "r");
	char buffer[100];
	while(fscanf(fp, "%s", buffer) == 1) {
		// printf("%s ", buffer);
		int ind = hash(buffer, bn, ts);
		node* it = table[ind].nxt;
		node* prev = it;
		if(it != NULL && strcmp(book[it->index], buffer) == 0) {
			// printf("found %s\n", buffer);
			table[ind].nxt = it->nxt;
			continue;
		}
		while(it != NULL) {
			if(strcmp(book[it->index], buffer) == 0) {
				// printf("found %s\n", buffer);
				prev->nxt = it->nxt;
				break;
			}
			prev = it;
			it = it->nxt;
		}
	}
	// printf("\n");
	fclose(fp);
	return profiling();
}

