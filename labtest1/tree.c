#include "tree.h"

unsigned int* createList(unsigned int p) {
	unsigned int* ar;
	ar = (int*)malloc(p*sizeof(int));
	// srand(time(0));
	srand(15042018);
	for(int i = 0; i < p; i++)
		ar[i] = (unsigned int)rand();
	return ar;
}
enum probability type() {
	srand(time(0));
	int r = rand()%3;
	if(r == 0)
		return LEMPTY;
	else if(r == 1)
		return REMPTY;
	else
		return NONEMPTY;
}
void addVertices(unsigned int *list, int lo, int hi, tree t, enum probability p){
	int mid = (lo+hi)/2;
	if(lo == hi) {
		t->data = list[lo];
		return;
	}
	if(p == LEMPTY) {
		t->data = list[lo];
		tree cur = (tree)malloc(sizeof(struct _tnode));
		cur->left = NULL;
		cur->right = NULL;
		t->right = cur;
		addVertices(list, lo+1, hi, cur, type());
	}
	else if(p == REMPTY) {
		tree cur = (tree)malloc(sizeof(struct _tnode));
		t->left = cur;
		cur->left = NULL;
		cur->right = NULL;
		if(lo == 0) {
			t->data = list[lo];
			addVertices(list, lo+1, hi, cur, type());
		}
		else {
			t->data = list[hi];
			addVertices(list, lo, hi-1, cur, type());
		}
	}
	else {
		tree cur1 = (tree)malloc(sizeof(struct _tnode));
		tree cur2 = (tree)malloc(sizeof(struct _tnode));
		if(lo == 0)
			t->data = list[lo];
		else
			t->data = list[mid];
		cur1->left = NULL; cur1->right = NULL; cur2->left = NULL; cur2->right = NULL;
		if(lo <= mid-1) {
			t->left = cur1;
			if(lo == 0)
				addVertices(list, lo+1, mid, cur1, type());
			else
				addVertices(list, lo, mid-1, cur1, type());
		}
		if(mid+1 <= hi) {
			t->right = cur2;
			addVertices(list, mid+1, hi, cur2, type());
		}
	}
}
// void addVertices(unsigned int *list, int lo, int hi, tree t, enum probability p){
// 	int mid = (lo+hi)/2;
// 	if(lo == hi) {
// 		t->data = list[lo];
// 		return;
// 	}
// 	if(p == LEMPTY) {
// 		t->data = list[lo];
// 		tree cur = (tree)malloc(sizeof(struct _tnode));
// 		cur->left = NULL;
// 		cur->right = NULL;
// 		t->right = cur;
// 		addVertices(list, lo+1, hi, cur, type());
// 	}
// 	else if(p == REMPTY) {
// 		t->data = list[lo];
// 		tree cur = (tree)malloc(sizeof(struct _tnode));
// 		t->left = cur;
// 		cur->left = NULL;
// 		cur->right = NULL;
// 		addVertices(list, lo+1, hi, cur, type());
// 	}
// 	else {
// 		t->data = list[lo];
// 		tree cur1 = (tree)malloc(sizeof(struct _tnode));
// 		tree cur2 = (tree)malloc(sizeof(struct _tnode));
// 		cur1->left = NULL; cur1->right = NULL; cur2->left = NULL; cur2->right = NULL;
// 		if(lo <= mid-1) {
// 			t->left = cur1;
// 			addVertices(list, lo+1, mid, cur1, type());
// 		}
// 		if(mid+1 <= hi) {
// 			t->right = cur2;
// 			addVertices(list, mid+1, hi, cur2, type());
// 		}
// 	}
// }
tree constructTree(unsigned int *list, unsigned int len) {
	tree t = (tree)malloc(sizeof(struct _tnode));
	t->left = NULL;
	t->right = NULL;
	addVertices(list, 0, len-1, t, type());
	return t;
}
bool matchTreeIterative(tree root, unsigned int *x, unsigned int size) {
	if(root == NULL)
		return true;
	int ar[size];
	int ind = 0;
	tree stack[size]; int pt = 0;
	ar[ind] = root->data; ind++;

	tree cur = root->left;
	while(pt != 0 || cur != NULL) {
		while(cur != NULL) {
			stack[pt] = cur; pt++;
			cur = cur->left;
		}
		cur = stack[pt-1]; pt--;
		ar[ind] = cur->data; ind++;
		cur = cur->right;
	}
	cur = root->right;
	while(pt != 0 || cur != NULL) {
		while(cur != NULL) {
			stack[pt] = cur; pt++;
			cur = cur->left;
		}
		cur = stack[pt-1]; pt--;
		ar[ind] = cur->data; ind++;
		cur = cur->right;
	}
	// for(int i = 0; i < ind; i++) {
	// 	printf("%u ", ar[i]);
	// }
	// printf("\n");
	// for(int i = 0; i < size; i++) {
	// 	printf("%u ", x[i]);
	// }
	// printf("\n");
	for(int i = 0; i < size; i++) {
		if(ar[i] != x[i])
			return false;
	}
	return true;
	pt++;
}

// bool matchTreeIterative(tree root, unsigned int *x, unsigned int size) {
// 	if(root == NULL)
// 		return true;
// 	int ar[size];
// 	int ind = 0;
// 	tree stack[size]; int pt = 0;
// 	ar[ind] = root->data; ind++;
// 	if(root->right != NULL) {
// 		stack[pt] = root->right;
// 		pt++;
// 	}
// 	if(root->left != NULL) {
// 		stack[pt] = root->left; 
// 		pt++;
// 	}

// 	while(pt != 0) {
// 		tree cur = stack[pt-1];
// 		pt--;
// 		ar[ind] = cur->data; ind++;
// 		if(cur->right != NULL) {
// 			stack[pt] = cur->right;
// 			pt++;
// 		}
// 		if(cur->left != NULL) {
// 			stack[pt] = cur->left;
// 			pt++;
// 		}
// 	}
// 	// for(int i = 0; i < ind; i++) {
// 	// 	printf("%u ", ar[i]);
// 	// }
// 	// printf("\n");
// 	// for(int i = 0; i < size; i++) {
// 	// 	printf("%u ", x[i]);
// 	// }
// 	// printf("\n");

// 	for(int i = 0; i < size; i++) {
// 		if(ar[i] != x[i])
// 			return false;
// 	}
// 	return true;
// 	pt++;
// }