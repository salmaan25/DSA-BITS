#include "bst.h"

void insert(int x, node* cur) {
	size++;
	if(cur->left = NULL && x <= cur->value) {
		node* tmp = (node*)malloc(sizeof(node));
		tmp->value = x;
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->balance = 0;
		cur->left = tmp;
		cur->balance -= 1;
	}
	else if(cur->right = NULL && x > cur->value) {
		node* tmp = (node*)malloc(sizeof(node));
		tmp->value = x;
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->balance = 0;
		cur->right = tmp;
		cur->balance += 1;
	}
	else {
		if(x <= cur->value) {
			cur->balance -= 1;
			insert(x, cur->left);
		}
		else {
			cur->balance += 1;
			insert(x, cur->right);
		}
	}
}
void add(int x) {
	if(head == NULL) {
		head = (node*)malloc(sizeof(node));
		head->value = x;
		head->left = NULL;
		head->right = NULL;
		head->balance = 0;
	}
	else {
		node* cur = head;
		insert(x, cur);
	}
}
int f(int x, node* cur, node* ar, int* ind) {
	// pair p;
	// p.parent = NULL;
	// p.child = NULL;
	// if(cur == NULL)
	// 	return p;
	// if(cur == head && cur->value == x) {
	// 	p.parent = head;
	// 	p.child = head;
	// 	return p;
	// }
	// if((cur->left == NULL && cur->value >= x) || (cur->right == NULL && cur->value < x))
	// 	return p;
	// if(cur->left != NULL && cur->left->value == x) {
	// 	p.parent = cur;
	// 	p.child = cur->left;
	// 	return p; 
	// }
	// if(cur->right != NULL && cur->right->value == x) {
	// 	p.parent = cur;
	// 	p.child - cur->right;
	// 	return p;
	// }
	// if(cur->right != NULL && cur->value < x)
	// 	return f(x, cur->right);
	// else
	// 	return f(x, cur->left)
	if(cur == NULL)
		return 0;
	if(cur->value == x) {
		ar[*ind] = cur;
		*ind += 1;
		return 1;
	}
	if(x <= cur->value) {
		ar[*ind] = cur;
		*ind += 1;
		return f(x, cur->left, ar, ind);
	}
	else {
		ar[*ind] = cur;
		*ind += 1;
		return f(x, cur->left, ar, ind);
	}
}

int find(int x) {
	node ar[size];
	int ind = 0;
	int end = f(x, head, ar, &ind);
	if(ar[end-1]->value == x)
		return 1;
	return 0;
}

pair suc(int x, node* cur) {
	pair p;
	p.parent = cur;
	p.child = cur->left;
	while(p.child->left != NULL) {
		p.parent = p.child;
		p.child = p.child->left;
	}
	return p;
}
pair successor(int x, node* cur) {
	pair p;
	p.parent = cur;
	p.child = cur->right;
	if(p.child->left == NULL)
		return p;
	else {
		return suc(x, p.child);
	}
}
void del(int x, pair p) {
	node* cur = p.child;
	if(p.child == NULL)
		return;
	// if(cur == head)
	if(cur->left != NULL && cur->right != NULL) {
		pair s = successor(x, cur);
		int tmp = s.child->value;
		s.child->value = p.child->value;
		p.child->value = tmp;
		del(x, s);
	}
	else {
		if(cur->left != NULL) {
			if(head == cur)
				head = cur->left;
			else {
				if(p.parent->left == cur)
					p.parent->left = cur->left;
				else
					p.parent->right = cur->left;
			}
		}
		else if(cur->right != NULL) {
			if(head == cur)
				head = cur->right;
			else {
				if(p.parent->left == cur)
					p.parent->left = cur->right;
				else
					p.parent->right = cur->right;
			}
		}
		else {
			if(cur == head)
				head = NULL;
			else {
				if(p.parent->left == cur)
					p.parent->left = NULL;
				else
					p.parennt->right = NULL;
			}
		}
	}
}
void delete(int x) {
	return del(x, find(x));
}






















#include "bst.h"

void insert(int x, node* cur) {
	size++;
	if(cur->left == NULL && x <= cur->value) {
		node* tmp = (node*)malloc(sizeof(node));
		tmp->value = x;
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->balance = 0;
		cur->left = tmp;
		cur->balance -= 1;
		//updatebalance();
	}
	else if(cur->right == NULL && x > cur->value) {
		node* tmp = (node*)malloc(sizeof(node));
		tmp->value = x;
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->balance = 0;
		cur->right = tmp;
		cur->balance += 1;
	}
	else {
		if(x <= cur->value) {
			cur->balance -= 1;
			insert(x, cur->left);
		}
		else {
			cur->balance += 1;
			insert(x, cur->right);
		}
	}
}
void add(int x) {
	if(head == NULL) {
		head = (node*)malloc(sizeof(node));
		head->value = x;
		head->left = NULL;
		head->right = NULL;
		head->balance = 0;
	}
	else {
		node* cur = head;
		insert(x, cur);
	}
}
void f(int x, node* cur, node* ar[], int* ind) {
	if(cur == NULL)
		return;
	if(cur->value == x) {
		ar[*ind] = cur;
		*ind += 1;
		return;
	}
	if(x <= cur->value) {
		ar[*ind] = cur;
		*ind += 1;
		return f(x, cur->left, ar, ind);
	}
	else {
		ar[*ind] = cur;
		*ind += 1;
		return f(x, cur->left, ar, ind);
	}
}

int find(int x) {
	node* ar[size];
	int ind = 0;
	f(x, head, ar, &ind);
	if(ind == 0)
		return 0;
	if(ar[ind-1]->value == x)
		return 1;
	return 0;
}

node* pseudo_successor(int x, node* cur) {
	cur = cur->right;
	while(cur->left != NULL)
		cur = cur->left;
	return cur;
}

void del(int x, node* n, node* p) {
	if(cur->left != NULL && cur->right != NULL) {

	}
	else if(cur->left != NULL) {
		if()
	}
	else if(cur->right != NULL) {

	}
	else {

	}
}
void delete(int x) {
	if(find(x) == 0)
		return;
	node* ar[size];
	int ind = 0;
	f(x, head, ar, &ind);
	del(x, ar[ind-1], );
}