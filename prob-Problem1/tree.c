/******************************************************
*           DSA Lab Test 2: Problem 1 (tree.c)
*   
*     Only fill up the missing function definitions.
* ****************************************************/
#include "tree.h"
#include "extras.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

unsigned int* createList(unsigned int p)
{
    unsigned int *list = NULL;
    
    // Write your code here.
    list=(unsigned int*)malloc(sizeof(unsigned int)*p);
    for(int i=0;i<p;++i)
    	list[i]=rand();
    
    return list;
}

tree constructTree(unsigned int *list, unsigned int len)
{
    tree t = NULL;
    
    // Write your code here.
    
    //base case
    if(len==0)
    	return t;
    	
    t=(tree)malloc(sizeof(struct _tnode));
    t->data=list[0];
    
    //prob = 0,1,2
    int prob=rand()%3;
    if(prob==0)
    {
    	t->left=NULL;
    	t->right=constructTree(list+1,len-1);
    }
    else if(prob==1)
    {
    	t->right=NULL;
    	t->left=constructTree(list+1,len-1);
    }
    else 
    {
    	int rlen,llen;
    	if((len-1)%2==0)
    		rlen=llen=(len-1)/2;
    	else
    	{
    		llen=(len-1)/2+1;
    		rlen=(len-1)/2;
    	}
    	
    	
    	t->left=constructTree(list+1,llen);
    	t->right=constructTree(list+llen+1,rlen);
    }
    return t;
}



bool matchTreeIterative(tree root,unsigned int *list,unsigned int size)
{
    bool status = false;
    
    // Write your code here.
    
    //note that it is not assumed that size of list is same as 
    //number of nodes in tree
    status=true;
    int i=0;
    stack s=createStack();
    s=push(s,root);
    tree t;
    printf("\n");
    while(!isEmpty(s)&&i<size)
    {
    	t=top(s);
    	s=pop(s);
    	while(t!=NULL&&i<size)
    	{
    		//if required to print the data 
    		//then please uncomment next line
    		printf("%u\t",t->data);
    		
    		//match with current list element
    		if(list[i]==t->data)
    			++i;
    		else
    		{
    			status=false;
    			break;
    		}
    		s=push(s,t->right);
    		t=t->left;
    	}
    	if(t!=NULL&&i==size)
    		status=false;
    	if(status==false)
    		break;
    }
    printf("\n");
    if(!isEmpty(s)&&i==size)
    {

    	status=false;
    }
    	
    //clearinig stack
    while(!isEmpty(s))
    	s=pop(s);
    return status;
}
