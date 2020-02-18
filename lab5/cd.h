typedef struct cd cd;
struct cd {
	int cn[16];
	char bc[6];
	int ed[6];
	char fn[30];
	char ln[30];
};

cd* insert(char* str, int ind, cd* h);
void printList(cd* h, int sz);
cd* init();
void insertInOrder(cd* h, int st);
void insertionSort(cd* h, int st, int sz);