#include "tree.h"
/*
struct node {
	char name[100];
	node* nxt;
	int isleaf;
};
*/

node* insert(node* cur, char* n) {
	node* tmp = cur->nxtc;
	while(tmp != NULL) {
		if(strcmp(n, tmp->name) == 0)
			return tmp;
		tmp = tmp->nxts;
	}
	tmp = (node*)malloc(sizeof(node));
	tmp->nxts = cur->nxtc;
	cur->nxtc = tmp;
	tmp->nxtc = NULL;
	tmp->isleaf = 0;
	strcpy(tmp->name, n);
	return tmp;
}
void readdata(FILE* fp) {
	head = (node*)malloc(sizeof(node));
	head->isleaf = 0;
	head->nxtc = NULL;
	strcpy(head->name, "NULL");
	int ct = 0;
	fscanf(fp, "%d", &ct);
	char n[100];
	char i[100];
	for(int ind = 0; ind < ct; ind++) {
		//while((getchar()) != '\n');
		fscanf(fp, "%s", n);
		fscanf(fp, "%s", i);
		printf("%s\n", n);
		node* cur = head;
		int l = strlen(n)-1, s = strlen(n);
		while(l >= -1) {
			if(n[l] == '.' || l == -1) {
				char str[100];
				for(int ind = l+1; ind < s; ind++)
					str[ind-l-1] = n[ind];
				str[s-l-1] = '\0';
				s = l;
				cur = insert(cur, str);
			}
			l--;
		}

		node* tmp = (node*)malloc(sizeof(node));
		strcpy(tmp->name, i);
		tmp->isleaf = 1;
		tmp->nxts = cur->nxtc;
		tmp->nxtc = NULL;
		cur->nxtc = tmp;
	}
}
void printdata(node* cur, char st[]) {
	while(cur != NULL) {
		if(cur->isleaf != 1) {
			char str[100];
			strcpy(str, st);
			int ind = strlen(st);
			for(int i = 0; i < strlen(cur->name); i++)
				str[i+ind] = cur->name[i];
			str[ind+strlen(cur->name)] = '\0';
			printdata(cur->nxtc, str);
		}
		else {
			printf("%s ", st);
			printf("%s\n", cur->name);
			// return;
		}
		cur = cur->nxts;
	}
}
void lookup(FILE* fp) {
	char buffer[100];
	int t;
	//while((getchar()) != '\n');
	fscanf(fp, "%s", buffer);
	// printf("%s njdc\n", buffer);
	node* cur = head->nxtc;
	int ar[100];
	int d = 0, l = strlen(buffer)-1, s = strlen(buffer);
	while(l >= -1) {
		if(buffer[l] == '.' || l == -1) {
			char str[100];
			for(int i = l+1; i < s; i++)
				str[i-l-1] = buffer[i];
			str[s-l-1] = '\0';
			s = l;
			// printf("%s\n", str);
			int f = 0;
			int ct = 0;
			while(cur != NULL) {
				if(strcmp(cur->name, str) == 0) {
					// printf("found %s\n", str);
					f=1;
					ar[d] = ct;
					d++;
					break;
				}
				ct++;
				cur=cur->nxts;
			}
			if(f == 0) {
				for(int i = 0; i < d; i++)
					printf("%d ", ar[i]);
				printf("\n");
				return;
			}
			else
				cur=cur->nxtc;
		}
		l--;
	}
	while(cur != NULL) {
		printf("%s ", cur->name);
		cur = cur->nxtc;
	}
	printf("\n");
}
char** extract(char* str, int* sz) {
	int ct = 0;
	for(int i = 0; i < strlen(str); i++) {
		if(str[i] == '.')
			ct++;
	}
	*sz = ct+1;
	char** s;
	s = (char**)malloc((ct+1)*sizeof(char*));
	int ind = 0;
	int st = strlen(str)-1, end = strlen(str);

	while(st >= -1) {
		// printf("%d\n", st);
		if(str[st] == '.' || st == -1) {
			s[ind] = (char*)malloc(100*sizeof(char));
			for(int i = st+1; i < end; i++)
				s[ind][i-st-1] = str[i];
			s[ind][end-st-1] = '\0';
			end = st;
			ind++;
		}
		st--;
	}
	return s;
}
node* lc(node* cur, char* str) {
	node* tmp = cur->nxtc;
	while(tmp != NULL) {
		if(strcmp(str, tmp->name) == 0)
			return tmp;
		tmp = tmp->nxts;
	}
	return NULL;
}

char* lca(char* s1, char* s2) {
	int sz1, sz2;
	char** t1 = extract(s1, &sz1);
	char** t2 = extract(s2, &sz2);

	// printf("in %d %d %s %s\n", sz1, sz2, s1, s2);
	// for(int i = 0; i < sz1; i++)
	// 	printf("%s\n", t1[i]);
	// for(int i = 0; i < sz2; i++)
	// 	printf("%s\n", t2[i]);
	// printf("in1\n");
	
	int ind1 = 0, ind2 = 0, st = 0;
	char* ans;
	ans = (char*)malloc(100*sizeof(char));
	node* n = head;
	node* nt = head;
	while(ind1 < sz1 && ind2 < sz2) {
		node* cur = n;
		n = lc(cur, t1[ind1]);
		nt = lc(cur, t2[ind2]);
		// printf("%s %s %s %s %d\n", n->name, nt->name, t1[ind1], t2[ind2], st);
		if(n == nt && n != NULL) {
			if(st != 0) {
				ans[st] = '.';
				st++;
			}
			// printf("in balle\n");
			for(int i = 0; i < strlen(t1[ind1]); i++) {
				ans[st] = t1[ind1][i];
				st++;
			}
			ind1++;
			ind2++;
		}
		else {
			ans[st] = '\0';
			return ans;
		}
	}
	ans[st] = '\0';
	return ans;
}

void find_lca(FILE* fp) {
	char s1[100], s2[100];
	fscanf(fp, "%s", s1);
	fscanf(fp, "%s", s2);
	// printf("%s %s\n",s1, s2);
	char* ans = lca(s1, s2);
	// printf("%s\n", ans);
	int len = 0;
	char** a = extract(ans, &len);
	for(int i = 0; i < len; i++) {
		if(i != 0)
			printf(".");
		printf("%s", a[i]);
	}
	printf("\n");
}