#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

int main(void) {
	
	int end = 512; //10
	int sz = 10240; //102400 //102
	char str[20];
	
	char name[20];
	float cg= 0.0;
	int i = 0;
	
	FILE *fp = fopen("input.txt","r");
	// FILE* fp1 = fopen("output.txt", "w");
	
	int r = 0;
	if(sz%end != 0)
		r = 1;
	int filect = sz/end + r;
	int fnames[filect];
	int fc = 0;
	for(int j = 0; j < filect; j++)
		fnames[j] = j;


	student ls[end];
	while(fscanf(fp,"%s",str) == 1) {
		if(i == end) {
			i = 0;
			char tmps[100];
			snprintf(tmps, 40, "%d.txt", fnames[fc]);
			FILE* ft = fopen(tmps, "w");
			sort(0, end-1, ls);
			// printf("in\n");
			for(int j = 0; j < end; j++) {
				fprintf(ft, "%s,%f\n", ls[j].name, ls[j].cgpa);
			}
			fclose(ft);
			fc++;
		}
		for(int j = 1; j < 11; j++)
			name[j-1] = str[j];
		name[10] = '\0';
		char ca[10];
		int ind = 12;
		for(ind = 12; str[ind] != '\"'; ind++)
			ca[ind-12] = str[ind];
		ca[ind-12] = '\0';
		cg = atof(ca);
		strcpy(ls[i].name, name);
		ls[i].cgpa = cg;
		i++;
	}
	if(i != 0) {
		//i.e r != 0
		char tmps[100];
		snprintf(tmps, 40, "%d.txt", fnames[fc]);
		FILE* ft = fopen(tmps, "w");
		sort(0, i-1, ls);
		for(int j = 0; j < i; j++) {
			fprintf(ft, "%s,%f\n", ls[j].name, ls[j].cgpa);
		}
		fclose(ft);
		fc++;
	}
	
	fclose(fp);
	//merge outputs and store in fp1
	collectMergeFile(0, filect-1);
	// fclose(fp1);
	return 0;
}
