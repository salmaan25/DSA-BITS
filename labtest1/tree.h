#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h> 

struct _tnode
{
    unsigned int data;
    struct _tnode *left, *right;
};

typedef struct _tnode *tree;
enum probability {LEMPTY, REMPTY, NONEMPTY};

unsigned int* createList(unsigned int p);
enum probability type();
void addVertices(unsigned int *list, int lo, int hi, tree t, enum probability p);
tree constructTree(unsigned int *list, unsigned int len);
bool matchTreeIterative(tree root, unsigned int *x, unsigned int size);