#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

// difference of 48 between consecutive addresses of pilani
// i.e 3757313304-3757313256=48,  3757313256-3757313208=48, 3757313208-3757313160=48
// in order bits, pilani, goa, hyd, dub
// 6295628 3757313304 3757313308 3757313312 3757313316
// in order bits, pilani, goa, hyd, dub
// 6295628 3757313256 3757313260 3757313264 3757313268
// in order bits, pilani, goa, hyd, dub
// 6295628 3757313208 3757313212 3757313216 3757313220
// in order bits, pilani, goa, hyd, dub
// 6295628 3757313160 3757313164 3757313168 3757313172

//part b
// 4284366332
// 4284366300
// 4284366268
// 4284366236
// 4284366204
// 4284366172
// 4284366140
// 4284366108
// 4284366076
// 4284366044

void p();
void q();
void h();
void d();
int bits;
void p() {
	int pilani, goa, hyd, dub;
	//GIVES ERROR 
	// printf("in order bits, pilani, goa, hyd, dub\n");
	// printf("%u %u %u %u %u\n", &bits, &pilani, &goa, &hyd, &dub);
	//ALTERNATIVE FOR NO ERROR
	printf("in order bits, pilani, goa, hyd, dub\n");
	printf("%u %u %u %u %u\n", (unsigned int)((uintptr_t)&bits), (unsigned int)((uintptr_t)&pilani), (unsigned int)((uintptr_t)&goa), (unsigned int)((uintptr_t)&hyd), (unsigned int)((uintptr_t)&dub));
	q();
}

void q() {
	int pilani, goa, hyd, dub;
	// printf("in order bits, pilani, goa, hyd, dub\n");
	// printf("%u %u %u %u %u\n", &bits, &pilani, &goa, &hyd, &dub);
	printf("in order bits, pilani, goa, hyd, dub\n");
	printf("%u %u %u %u %u\n", (unsigned int)((uintptr_t)&bits), (unsigned int)((uintptr_t)&pilani), (unsigned int)((uintptr_t)&goa), (unsigned int)((uintptr_t)&hyd), (unsigned int)((uintptr_t)&dub));
	h();
}

void h() {
	int pilani, goa, hyd, dub;
	// printf("in order bits, pilani, goa, hyd, dub\n");
	// printf("%u %u %u %u %u\n", (unsigned int)&bits, (unsigned int)&pilani, (unsigned int)&goa, (unsigned int)&hyd, (unsigned int)&dub);
	printf("in order bits, pilani, goa, hyd, dub\n");
	printf("%u %u %u %u %u\n", (unsigned int)((uintptr_t)&bits), (unsigned int)((uintptr_t)&pilani), (unsigned int)((uintptr_t)&goa), (unsigned int)((uintptr_t)&hyd), (unsigned int)((uintptr_t)&dub));
	d();
}

void d() {
	int pilani, goa, hyd, dub;
	// printf("in order bits, pilani, goa, hyd, dub\n");
	// printf("%u %u %u %u %u\n", &bits, &pilani, &goa, &hyd, &dub);
	printf("in order bits, pilani, goa, hyd, dub\n");
	printf("%u %u %u %u %u\n", (unsigned int)((uintptr_t)&bits), (unsigned int)((uintptr_t)&pilani), (unsigned int)((uintptr_t)&goa), (unsigned int)((uintptr_t)&hyd), (unsigned int)((uintptr_t)&dub));
}

//part b
void b(int ct) {
	if(ct==1000000)
		return;
	// printf("%u\n", (unsigned int)((uintptr_t)&ct));
	return b(ct+1);
}

int main(void) {
	p();
	b(0);
	return 0;	
}