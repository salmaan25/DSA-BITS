#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int baseNumber,tableSize;
struct node;
typedef struct node node;
typedef node* NODE;

struct Book;
typedef struct Book Book;
typedef Book* BOOK;

struct Book
{
	char** book;
	int size;

};

struct node
{
	int index;
	int count;
	char *str;
	NODE next;

};


typedef struct
{
	int elementCount;
	int insertionCost;
	int queryingCost;
	NODE*  arrLink;
	

}hash;

typedef hash* hashtable;

BOOK parsing(FILE *fp);
int hashFunction(char *str);
int collisionCount(char** strArr,int size);
void profiling(char **book,int size);

hashtable Creation();
void Insert(hashtable ht,char** A,int j);
int InsertAll(hashtable ht,char** book,int size);
NODE Lookup(hashtable ht,char* str);
int LookupAll(hashtable ht,char** A,int size,float m);
void deletehash(hashtable ht,char* str);

float Profiling(hashtable ht,char** book,int size);
float Cleanup(hashtable ht,FILE *fp,char** book,int size);
