typedef struct student student;
struct student {
	char name[10];
	float cgpa;
};

void merge(student ls1[], int sz1, student ls2[], int sz2, student ls[]);
void sort(int l, int r, student ls[]);
void iter_sort(student ls[], int sz);
int min(int a, int b);
void mergeF(int in1, int in2, int out);
void collectMergeFile(int st, int end);