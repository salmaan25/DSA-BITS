#include "hash.h"

int hashFunction(char *str)
{
	int sum=0,j,base,func;
	for(int i=0;i<strlen(str);i++)
	{
		j=str[i];
		sum=sum+j;
	
	}
	base=sum%baseNumber;
	func=base%tableSize;
	return func;

}

int collisionCount(char** strArr,int size)
{
	int index,count=0;
	int* temp=(int*)malloc(tableSize*sizeof(int));
	for(int i=0;i<tableSize;i++)
	{
		temp[i]=-1;
	
	}
	
	for(int i=0;i<size;i++)
	{
		index=hashFunction(strArr[i]);
		if(temp[index]==-1)
		{
			temp[index]=1;
		}
		else
		{
			count++;	
		}
	
	}
	free(temp);
	return count;


}

BOOK parsing(FILE *fp)
{
	char temp[100000][15];
	char str;
	int z,x;
	char c;
	x=0;
	int count=0;
	while(1)
	{
		z=0;count=0;
		c=fgetc(fp);
		if(feof(fp))
		{
			break;

		}
		while(c>='a' && c<='z' || c>='A' && c<='Z')
		{
			
			count=1;
			temp[x][z]=c;
			z++;
			c=fgetc(fp);
			if(feof(fp))
			{
				break;
		
			}
		}
		if(count==1)
		{
			temp[x][z]='\0';
			x++;
		}
		if(feof(fp))
		{
			break;
	
		}
		
		
	}
	BOOK new=(BOOK)malloc(sizeof(Book));
	new->book=(char**)malloc(x*sizeof(char*));
	for(int j=0;j<x;j++)
	{
		new->book[j]=(char*)malloc((strlen(temp[j])+1)*sizeof(char));
		strcpy(new->book[j],temp[j]);
	
	}
	printf("number of valid strings %d \n",x);
	
	new->size=x;
	return new;
}

void profiling(char **book,int size)
{
	int baseNumber1[3][6],tableSize1[3];
	tableSize1[0]=5000;
	tableSize1[1]=50000;
	tableSize1[2]=500000;
	int baseindexmin;
	int tableindexmin;
	int count;
	int countMin=1000000;
	int basenumin,tablemin;
	for(int i=0;i<3;i++)
	{
			int basecount=0;
			for(int z=tableSize1[i];z<2*tableSize1[i];z++)
			{
				int flag=0;
				for(int j=2;j<z/2;j++)
				{
					if(z%j==0)
					{
						flag=1;
						break;
					}
				
				}
				if(flag ==0)
				{
					baseNumber1[i][basecount]=z;
					printf("%d",z);
					basecount++;
				}
				if(basecount>=3)
				{
					break;
				}
				
			}
			for(int z=1000*tableSize1[i];;z++)
			{
				int flag=0;
				for(int j=2;j<=z/2;j++)
				{
					if(z%j==0)
					{
						flag=1;
					}
				
				}
				if(flag ==0)
				{
					baseNumber1[i][basecount]=z;
					basecount++;
				}
				if(basecount>=6)
				{
					break;
				}
			
			}
			
	
	}
	int i=0;
	while(i<3)
	{
		tableSize=tableSize1[i];
		for(int x=0;x<6;x++)
		{
			baseNumber=baseNumber1[i][x];
			
			count=collisionCount(book,size);
			printf("collisioncount for baseNumer %d  and tableSize  %d  is %d \n",baseNumber1[i][x],tableSize1[i],count);
			if(count <countMin)
			{
				countMin=count;
				basenumin=baseNumber1[i][x];
				tablemin=tableSize1[i];
				baseindexmin=x+1;
				tableindexmin=i+1;
			
			}
	
		}
		i++;
	}
	
	baseNumber=basenumin; tableSize=tablemin;
	printf("best choice of basenumber is %d index is %d and for tableSize is %d index is %d which gives count %d \n",basenumin,baseindexmin,tablemin,tableindexmin,countMin);
		

}



hashtable Creation()
{
	hashtable ht=(hashtable)malloc(sizeof(hash));
	ht->elementCount=0;
	ht->insertionCost=0;
	ht->queryingCost=0;
	ht->arrLink=(NODE*)malloc(tableSize*sizeof(NODE));
	for(int i=0;i<tableSize;i++)
	{
		ht->arrLink[i]=NULL;
	
	} 
	return ht;

}

void Insert(hashtable ht,char** A,int j)
{
	if(ht==NULL)
	{
		printf("hashtable invalid\n");
		return ;
	}
	int index=hashFunction(A[j]);
	NODE temp=ht->arrLink[index];
	if(temp==NULL)
	{
		NODE new=(NODE)malloc(sizeof(node));
		new->count=1;
		new->index=j;
		new->str=(char*)malloc((strlen(A[j])+1)*sizeof(char));
		strcpy(new->str,A[j]);
		new->next=NULL;
		ht->arrLink[index]=new;
		ht->elementCount++;
		return ;

	}
	while(temp->next!=NULL && strcmp(temp->str,A[j])!=0)
	{
		temp=temp->next;
		ht->insertionCost++;
	
	}
	if(strcmp(temp->str,A[j])==0)
	{
		temp->count++;
		
	
	}
	else
	{
		NODE new=(NODE)malloc(sizeof(node));
		new->count=1;
		new->index=j;
		new->str=(char*)malloc((strlen(A[j])+1)*sizeof(char));
		strcpy(new->str,A[j]);
		new->next=NULL;
		temp->next=new;
		ht->elementCount++;
	}
	

}

int InsertAll(hashtable ht,char** book,int size)
{
	for(int i=0;i<size;i++)
	{
		Insert(ht,book,i);
	
	}
	return ht->insertionCost;
}

NODE Lookup(hashtable ht,char* str)
{
	if(ht==NULL)
	{
		printf("hashtable invalid\n");
		return NULL;
	}
	int index=hashFunction(str);
	NODE temp=ht->arrLink[index];
	if(temp==NULL)
	{
		printf("%s not in hashtable\n",str);
		ht->queryingCost++;
		return NULL;
		

	}
	while(temp->next!=NULL && strcmp(temp->str,str)!=0)
	{
		temp=temp->next;
		ht->queryingCost++;
	
	}
	if(strcmp(temp->str,str)==0)
	{
		ht->queryingCost++;
		return temp; 
		
	
	}
	else
	{
		return NULL;
	}

}

int LookupAll(hashtable ht,char** A,int size,float m)
{
		int entries=m*size;
		int z;
		for(int i=0;i<entries;i++)
		{
			z=i%size;
			NODE temp=Lookup(ht,A[z]);
		}
		return ht->queryingCost;



}


void deletehash(hashtable ht,char* str)
{
	if(ht==NULL)
	{
		printf("hashtable invalid\n");
		return ;
	}
	int index=hashFunction(str);
	NODE temp=ht->arrLink[index];
	NODE prev=temp;
	if(temp==NULL)
	{
		//printf("%s not in hashtable\n",str);
		return ;
		

	}
	while(temp->next!=NULL && strcmp(temp->str,str)!=0)
	{
		prev=temp;
		temp=temp->next;
	
	}
	if(strcmp(temp->str,str)==0)
	{
		prev=temp->next; 
	}


}






float Profiling(hashtable ht,char** book,int size)
{
	int queringCost;
	float m=0.10;
	for(int i=1;i<20;i++)
	{
		queringCost=LookupAll(ht,book,size,m);
		if(queringCost>=ht->insertionCost)
		{
			return m;
	
		}
		ht->queryingCost=0;
		m=m+0.10;
	}

}

float Cleanup(hashtable ht,FILE *fp,char** book,int size)
{
	char** stop=(char**)malloc(1000*sizeof(char*));
	char wrd[1000];
	int z=1000;
	int i=0;
	while(1)
	{
		if(i>=z)
		{
			z=2*z;
			stop=(char**)realloc(stop,z*sizeof(char*));
		
		}
		fscanf(fp,"%s ",wrd);
		stop[i]=(char*)malloc((strlen(wrd)+1)*sizeof(char));
		strcpy(stop[i],wrd);
		if(feof(fp))
		{
			break;
		}
		i++;
	
	}
	for(int j=0;j<i;j++)
	{
		deletehash(ht,stop[i]);
	}
	float per=Profiling(ht,book,size);
	return per;

}










