#include "test.h"
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
	return a<=b?a:b;
}
void merge(student ls1[], int sz1, student ls2[], int sz2, student ls[]) {
	int i1 = 0, i2 = 0, i = 0;
	while(1) {
		if(i1 == sz1 || i2 == sz2)
			break;
		if(ls1[i1].cgpa <= ls2[i2].cgpa) {
			ls[i] = ls1[i1];
			i1++;
			i++;
		}
		else {
			ls[i] = ls2[i2];
			i2++;
			i++;
		}
	}
	if(i1 != sz1) {
		for(int j = i1; j < sz1; j++) {
			ls[i] = ls1[j];
			i++;
		}
	}
	if(i2 != sz2) {
		for(int j = i2; j < sz2; j++) {
			ls[i] = ls2[j];
			i++;
		}
	}
}

void sort(int l, int r, student ls[]) {
	if(l == r)
		return;
	int mid = (l+r)/2;
	sort(l, mid, ls);
	sort(mid+1, r, ls);
	student ls1[mid-l+1], ls2[r-mid], sorted[r-l+1];
	for(int i = l; i <= mid; i++)
		ls1[i-l] = ls[i];
	for(int i = mid+1; i <= r; i++)
		ls2[i-mid-1] = ls[i];
	merge(ls1, mid-l+1, ls2, r-mid, sorted);
	for(int i = l; i <= r; i++)
		ls[i] = sorted[i-l];
}

void iter_sort(student ls[], int sz) {
	int l = 0, r = sz-1;
	int i_sz = 1;
	while(i_sz < sz) {
		for(int i = 0; i < sz; i = i + 2*i_sz) {
			student ls1[i_sz];
			int sz1 = min(i_sz, sz-i), sz2 = min(i_sz, sz-i-sz1);
			student ls2[sz2];
			//printf("%d  %d   %d   %d\n", i, i+sz1+sz2, i_sz, sz-i-i_sz);
			for(int j = i; j < i + sz1; j++) {
				ls1[j-i] = ls[j];	
			}
			for(int j = i+sz1; j < i+sz1+sz2; j++) {
				ls2[j-sz1-i] = ls[j];
			}
			student sorted[sz1+sz2];
			if(sz2 != 0) {
				merge(ls1, sz1, ls2, sz2, sorted);
				for(int j = i; j < i+sz1+sz2; j++) {
					//printf("%f ", sorted[j-i].cgpa);
					ls[j] = sorted[j-i];
				}
				//printf("\n");
			}
		}
		i_sz = i_sz<<1;
	}
}
void mergeF(int in1, int in2, int out) {
	char s[100];
	snprintf(s, 99, "%d.txt", in1);
	FILE* i1 = fopen(s, "r");
	snprintf(s, 99, "%d.txt", in2);
	FILE* i2 = fopen(s, "r");
	snprintf(s, 99, "%d.txt", out);
	FILE* o = fopen(s, "w");
	int r1 = 1, r2 = 1;
	char name1[20], name2[20];
	float cg1, cg2;
	int flag = -1;
	fscanf(i1, "%10s,%f", name1, &cg1);
	fscanf(i2, "%10s,%f", name2, &cg2);
	
	while(1) {
		if(r1 == 1 && r2 == 1) {
			if(cg2 < cg1) {
				fprintf(o, "%s,%f\n", name2, cg2);
				r2 = 0;
			}
			else {
				fprintf(o, "%s,%f\n", name1, cg1);
				r1 = 0;
			}
		}
		else if(r1 == 1 && r2 == 0) {
			if(fscanf(i2, "%10s,%f", name2, &cg2) != 2) {
				flag = 2;
				break;
			}
			r2 = 1;
		}
		else if(r1 == 0 && r2 == 1) {
			if(fscanf(i1, "%10s,%f", name1, &cg1) != 2) {
				flag = 1;
				break;
			}
			r1 = 1;
		}
	}
	if(flag == 1) {
		if(r2 == 1)
			fprintf(o, "%s,%f\n", name2, cg2);
		while(fscanf(i2, "%10s,%f", name2, &cg2) == 2) {
			fprintf(o, "%s,%f\n", name2, cg2);
		}
	}
	else if(flag == 2) {
		if(r1 == 1)
			fprintf(o, "%s,%f\n", name1, cg1);
		while(fscanf(i1, "%10s,%f", name1, &cg1) == 2) {
			fprintf(o, "%s,%f\n", name1, cg1);
		} 
	}
	fclose(i1); fclose(i2); fclose(o);
}
void collectMergeFile(int st, int end) {
	// printf("%d %d\n", st, end);
	if(end == st) {
		FILE* fp = fopen("output.txt", "w");
		char s[100];
		snprintf(s, 99, "%d.txt", st);
		FILE* fp1 = fopen(s, "r");
		char buf[100];
		while(fscanf(fp1, "%s", buf) == 1)
			fprintf(fp, "%s\n", buf); //remove \n if double new lines are printed
		fclose(fp1); fclose(fp);
		return;
	}
	int nst = end+1, cur = end+1;
	for(int i = st; i < end; i+=2) {
		// printf("in %d %d\n", st, st+1);
		mergeF(i, i+1, cur);
		cur++;
	}
	if((end-st+1)%2 == 1) {
		char s[100];
		snprintf(s, 99, "%d.txt", cur);
		FILE* fp1 = fopen(s, "w");

		snprintf(s, 99, "%d.txt", end);
		FILE* fp2 = fopen(s, "r");

		char buf[100];
		while(fscanf(fp2, "%s", buf) == 1)
			fprintf(fp1, "%s\n", buf); //remove \n if double new lines are printed
		cur++;
		fclose(fp1); fclose(fp2);
	}
	collectMergeFile(nst, cur-1);
}