#include "tree.h"

void printList(unsigned int *list, unsigned int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%u ", list[i]);
    printf("\n");
}

void printTreeInorder(tree root)
{
    if(root != NULL)
    {
        printTreeInorder(root->left);
        printf("%u ", root->data);
        printTreeInorder(root->right);
    }
}

int main(void) {
	int p = 20;
	unsigned int *list = createList(p);
    printList(list, p);
    tree root = constructTree(list, p);
    printTreeInorder(root);
    printf("\n");
    bool status = matchTreeIterative(root, list, p);
    (status)? printf("\nCORRECT\n"): printf("\nWRONG\n");
}
