#include "bst.h"

void init(node* tmp) {
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->balance = 0;
	tmp->lheight = 0;
	tmp->rheight = 0;
}
int max(int a, int b) { return a>=b?a:b; }

void update(node* cur) {
	node* tmp;
	int lh = 0, rh = 0;
	if(cur->left != NULL) {
		// printf("in11\n");
		tmp = cur->left;
		lh = max(tmp->lheight, tmp->rheight)+1; 
	}
	if(cur->right != NULL) {
		// printf("in12\n");
		tmp = cur->right;
		rh = max(tmp->lheight, tmp->rheight)+1;
	}
	cur->lheight = lh; cur->rheight = rh;
	cur->balance = rh-lh;
}

void insert(int x, node* cur) {
	node* tmp = (node*)malloc(sizeof(node));
	if(cur == NULL)
		return;
	if(cur->left != NULL && cur->right != NULL) {
		if(cur->value >= x)
			insert(x, cur->left);
		else
			insert(x, cur->right);
	}
	else if(cur->left != NULL) {
		if(cur->value >= x)
			insert(x, cur->left);
		else {
			init(tmp);
			tmp->value = x;
			cur->right = tmp;
		}
	}
	else if(cur->right != NULL) {
		if(cur->value < x)
			insert(x, cur->right);
		else {
			init(tmp);
			tmp->value = x;
			cur->left = tmp;
		}
	}
	else {
		init(tmp);
		tmp->value = x;
		if(cur->value >= x) {
			cur->left = tmp;
		}
		else {
			cur->right = tmp;
		}
	}
	update(cur);
	if(abs(cur->right-cur->left) >= 2) {
		node* y = parent(cur);
		node* z = parent(y);
		if(y == cur) {
			y = NULL;
			z = NULL;
		}
		if(y == z) {
			z = NULL;
		}
		if(z == head) {
			node * tmp = rotate(z, y, cur);
			head = tmp;
		}
		else {
			if(z != NULL) {
				node* papa = parent(z);
				node * tmp = rotate(z, y, cur);
				if(papa->left == z)
					papa->left = tmp;
				else
					papa->right = tmp;
			}
		}
	}
}

void add(int x) {
	if(head == NULL) {
		size = 1;
		head = (node*)malloc(sizeof(node));
		init(head);
		head->value = x;
		return;
	}
	size++;
	insert(x, head);
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
		return f(x, cur->right, ar, ind);
	}
}

node* find(int x) {
	node* ar[size];
	int ind = 0;
	f(x, head, ar, &ind);
	if(ind == 0)
		return NULL;
	if((ar[ind-1])->value == x)
		return ar[ind-1];
	return NULL;
}



node* pseudo_successor(node* cur) {
	cur = cur->right;
	while(cur->left != NULL) {
		cur = cur->left;
	}
	return cur;
}
node* parent(node* tmp) {
	node* cur = head;
	node* par = head;
	while(cur != NULL) {
		if(cur == tmp)
			return par;
		par = cur;
		if(cur->value >= tmp->value)
			cur = cur->left;
		else
			cur = cur->right;
	}
}

void __remove(int x, node* cur) {
	if(cur == NULL)
		return;
	if(cur->value == x) {
		if(cur->left != NULL && cur->right != NULL) {
			node* rep = pseudo_successor(cur);
			int tp = cur->value;
			cur->value = rep->value;
			rep->value = tp;
			if(cur->value >= x)
				__remove(x, cur->left);
			else
				__remove(x, cur->right);
		}
		else if(cur->left != NULL) {
			if(cur == head) {
				head = head->left;
				cur = head;
			}
			else {
				node* par  = parent(cur);
				if(par->left == cur) {
					par->left = cur->left;
					cur = par->left;
				}
				else {
					par->right = cur->left;
					cur = par->right;
				}
			}
		}
		else if(cur->right != NULL) {
			if(cur == head) {
				head = head->right;
				cur = head;
			}
			else {
				node* par  = parent(cur);
				if(par->left == cur) {
					par->left = cur->right;
					cur = par->left;
				}
				else {
					par->right = cur->right;
					cur = par->right;
				}
			}
		}
		else {
			node* par  = parent(cur);
			if(par->left == cur)
				par->left = NULL;
			else
				par->right = NULL;
		}
	}
	else if(cur->value > x) {
		__remove(x, cur->left);
	}
	else {
		__remove(x, cur->right);
	}
	update(cur);
	if(abs(cur->right-cur->left) >= 2) {
		node* y = parent(cur);
		node* z = parent(y);
		if(y == cur) {
			y = NULL;
			z = NULL;
		}
		if(y == z) {
			z = NULL;
		}
		if(z == head) {
			node * tmp = rotate(z, y, cur);
			head = tmp;
		}
		else {
			if(z != NULL) {
				node* papa = parent(z);
				node * tmp = rotate(z, y, cur);
				if(papa->left == z)
					papa->left = tmp;
				else
					papa->right = tmp;
			}
		}
	}
}
void delete(int x) {
	if(find(x) == NULL) {
		return;
	}
	size--;
	__remove(x, head);
}

node* inorderkth(int k) {
	if(k >= size)
		return NULL;
	node* stack[size]; int pt = 0;
	int ind = 0;
	node* cur = head;
	while(cur != NULL || pt != 0) {
		while(cur != NULL) {
			stack[pt] = cur; pt++;
			cur = cur->left;
		}
		cur = stack[pt-1]; pt--;
		ind++;
		if(ind == k)
			return cur;
		cur = cur->right;
	}
}
void range(node* cur, int l, int r, int* ar, int* ind) {
	if(cur == NULL) {
		return;
	}
	if(cur->value >= l && cur->value <= r) {
		range(cur->left, l, r, ar, ind);
		ar[*ind] = cur->value;
		*ind += 1;
		range(cur->right, l, r, ar, ind);
	}
	if(cur->value > r) {
		range(cur->left, l, r, ar, ind);
	}
	else if(cur->value < l) {
		range(cur->right, l, r, ar, ind);
	}
}


node* rotate(node* z, node* y, node* x){   //y is parent of x and z is parent of y

    if(x==NULL||y==NULL||z==NULL) {return NULL; printf("problem 1 of rotate\n");}

    node *a, *b, *c, *t0, *t1, *t2, *t3;
    if(y->left==x && z->left==y) {
        a=x; b=y; c=z;
        t0 = x->left;
        t1 = x->right;
        t2 = y->right;
        t3 = z->right;
    //    printf("case1\n");

    }
    else if(y->right==x && z->left==y) {
        a=y; b=x; c=z;
        t0 = y->left;
        t1 = x->left;
        t2 = x->right;
        t3 = z->right;
    //    printf("case2\n");

    }
    else if(y->right==x && z->right==y) {
        a=z; b=y; c=x;
        t0 = z->left;
        t1 = y->left;
        t2 = x->left;
        t3 = x->right;
    //    printf("case3\n");

    }
    else if(y->left==x && z->right==y) {
        a=z; b=x; c=y;
        t0 = z->left;
        t1 = x->left;
        t2 = x->right;
        t3 = y->right;
    //    printf("case4\n");

    }
    else {printf("Not among 4 cases\n"); return NULL;}


    b->left = a;
    b->right = c;
    a->left = t0;
    a->right = t1;
    c->left = t2;
    c->right = t3;

    update(a);
    update(c);
    update(b);

    return b;
}