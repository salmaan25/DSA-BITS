#include "qsort.h"


int main(int argc, char* argv[])
{
	size = 0;
	
	char * fileName = argv[1];
	printf("%s\n",fileName);

	int* studentArray = readData(fileName);
	// size = 1;
	// KeyStruct extractKeys();
	// int studentArray[] = {11, 7 , 6 , 2, 7, 13, 5, 4, 10};
	printArray(studentArray, size);
	quickSortKnownKeyRange(studentArray,size, 3, 11);

	printf("\nSorted output is:\n");

	printArray(studentArray, size);
	
}
