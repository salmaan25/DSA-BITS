#include "qsort.h"
void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
	FILE* fp = fopen("output.txt", "w");
	for(int i = 0; i < arrSize; i++)
		fprintf(fp, "%d\n", studArray[i]);
	fclose(fp);
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

//IMPORTANT
// fscanf(fileptr,"%[^\n]",str);

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
	int ct = 0, ind = -1;
	for(int i = lo; i <= hi; i++) {
		if(Ls[i] <= piv)
			ct++;
		if(Ls[i] == piv)
			ind = i;
	}
	int piv_ind = ct-1;
	int tmp = Ls[piv_ind];
	Ls[piv_ind] = piv; Ls[ind] = tmp;
	int p1 = lo, p2 = hi;
	while(p1 < piv_ind && p2 > piv_ind) {
		if(Ls[p1] > piv && Ls[p2] <= piv) {
			int tmp = Ls[p1];
			Ls[p1] = Ls[p2];
			Ls[p2] = tmp;
		}
		else if(Ls[p1] > piv)
			p2--;
		else if(Ls[p2] <= piv)
			p1++;
		else {
			p2--;
			p1++;
		}
	}
	return piv_ind;
}

void quickSortKnownKeyRange(int * Ls, int size, int loKey, int hiKey) {
	if(size == 1)
		return;
	int piv = (loKey+hiKey)/2;
	int dif = (piv-Ls[0]>=0?(piv-Ls[0]):(Ls[0]-piv));
	int min = Ls[0];
	for(int i = 1; i < size; i++) {
		int tmp = (piv-Ls[i]>=0?(piv-Ls[i]):(Ls[i]-piv));
		if(tmp < dif) {
			dif = tmp;
			min = Ls[i];
		}
	}
	int part = part2Loc(Ls, 0, size-1, min);
	if(part > 0)
		quickSortKnownKeyRange(Ls, part, loKey, min);
	if(size-part-1 > 0)
		quickSortKnownKeyRange(Ls+part+1, size-part-1, min, hiKey);
}
