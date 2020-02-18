#include "hash.h"

int main(void) {
	readFile();
	// for(int i = 0; i < wct; i++) {
	// 	if(i == 100)
	// 		break;
	// 	printf("%s\n", book[i]);
	// }
	printf("%d\n", wct);
	int mini = profile();
	printf("%d %d %d \n", mini, bn, ts);
	create();
	// insert("Adventures", 0);
	int cost = insertAll();
	// record rec = lookup("sister");
	printf("%d\n", cost);
	// cost = lookupAll(10);
	// int m = 0;
	// while(m <= 100){
	// 	cost = lookupAll(m);
	// 	printf("%d %d\n", cost, m);
	// 	m += 5;
	// }
	printf("%d\n", profiling());
	printf("%d\n", cleanup());
	return 0;
}