/******************************************************
*           DSA Lab Test 2: Problem 2 (graph.c)
*   
*     Only fill up the missing function definitions.
* ****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "graph.h"
#include "extras.h"


Graph initGraph(int N)
{
    Graph g = NULL;
    
    // Write your code here.
    g=(Graph)malloc(sizeof(struct _Graph));
    g->list=(node)malloc(sizeof(struct _node)*N);
    	
    g->wt=(int*)malloc(sizeof(int)*N);
    g->visited=(bool*)malloc(sizeof(int)*N);
    for(int i=0;i<N;++i)
    {
    	g->list[i].next=NULL;
    	g->visited[i]=false;
    }
    g->vcount=N;
    g->ecount=0;
    
    return g;
}
void printAdjacencyList(Graph g)
{
    // Write your code here.
    printf("\n");
    for(int i=0;i<g->vcount;++i)
    {
    	printf("%d\t (%d) ==> ",i,g->wt[i]);
    	node t=g->list[i].next;
    	while(t!=NULL)
    	{
    		printf("%u ",t->id);
    		t=t->next;
    	}
    	printf("\n");
    }
}

void insertEdge(Graph g, unsigned int u, unsigned int v)
{
    // Write your code here.
    node t=(node)malloc(sizeof(struct _node));
    t->id=v;
    t->next=g->list[u].next;
    g->list[u].next=t;
}
void bestFirstTraverse(Graph g, unsigned int root)
{
    // Write your code here.
    
    // output given in problem PDF is wrong, 6 is not reachable
    // from 0, so it won't be printed
    printf(" (root is %u)\n",root);
    heap curset=createHeap(g->vcount);
    hnode n;
    n.id=root;
    n.w=g->wt[root];
    curset=insert(curset,n);
    g->visited[root]=true;
    while(!isEmpty(curset))
    {
    	unsigned int cur=max(curset);
    	printf("%u ",cur);
    	curset=deletemax(curset);
    	node temp=g->list[cur].next;
    	while(temp!=NULL)
    	{
    		if(g->visited[temp->id]==false)
    		{
    			g->visited[temp->id]=true;
    			n.id=temp->id;
    			n.w=g->wt[temp->id];
    			curset=insert(curset,n);
    		}
    		temp=temp->next;
    	}
    }
    	
}
