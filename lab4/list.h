typedef struct node node;
typedef struct head head;
struct node {
	int val;
	node* nxt;
};
struct head {
	int size;
	node* ff;
};

void* myalloc(int type);
void myfree(node* n); 
head* createList(int sz);
void printList(head* h);
void printSpace();
void createCycle(head* h, int sz);