#include "qsort.h"

void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}

int* readData(char * fileName) {
	FILE* fp = fopen(fileName, "r");
	int * a;
	char buf[30];
	int space = 0;
	int ct = 0;
	while(fscanf(fp, "%s", buf) == 1) {
		if(ct != 0) {
			char name[30];
			strcpy(name, buf);
			int marks;
			fscanf(fp, "%d", &marks);
			a[ct-1] = marks;
			printf("%s %d\n", buf, marks);	
		}
		else {
			size = atoi(buf);
			a = (int*)malloc(size*sizeof(int));
		}
		ct++;
	}
	return a;
}
/*
struct keyStruct
{
	int* Keys;
	int keysSize;
};
*/
KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey) {
	KeyStruct ks = (KeyStruct)malloc(sizeof(struct keyStruct));
	int pr[hiKey-loKey+1];
	for(int i = 0; i < hiKey-loKey+1; i++)
		pr[i] = 0;
	int ct = 0;
	for(int i = 0; i < lsSize; i++){
		if(pr[Ls[i]-loKey] == 0) {
			pr[Ls[i]-loKey] = 1;
			ct++;
		}
	}
	ks->Keys = (int *)malloc(ct*sizeof(int));
	int ind = 0;
	for(int i = 0; i < hiKey-loKey+1; i++) {
		if(pr[i] == 1) {
			ks->Keys[ind] = i+loKey;
			ind++;
		}
	}
	return ks;
}

int part2Loc(int* Ls, int lo, int hi, int piv) {
	while(lo != hi) {
		if(Ls[lo] <= piv
	}
}

void quickSortKnownKeyRange(int * Ls, int size, int loKey, int hiKey) {
	
}
