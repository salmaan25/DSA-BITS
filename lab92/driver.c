#include "hash.h"

int main()
{
	FILE *fp=fopen("aliceinwonderland.txt","r");
	if(fp==NULL)
	{
		printf("file read error\n");
		return 0;
	}
	BOOK book1=parsing(fp);	
	/*for(int i=0;i<book1->size;i++)
	{
		printf("%s\n",book1->book[i]);
	
	}*/
	
	//profiling(book1->book,book1->size);
	
		baseNumber=5011; tableSize=5000;
		// printf("%d\n",collisionCount(book1->book,book1->size));
		hashtable ht=Creation();
		printf("%d\n",InsertAll(ht,book1->book,book1->size));
		printf("%d\n",LookupAll(ht,book1->book,book1->size,0.1));
		printf("%f\n",Profiling(ht,book1->book,book1->size));
		FILE *fp2=fopen("stopwords.txt","r");
		if(fp2==NULL)
		{
			printf("file read error\n");
			return 0;
		}

		printf("%f\n",Cleanup(ht,fp2,book1->book,book1->size));

	
}
