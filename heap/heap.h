#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int hp_sz;
int left(int* hp, int p);
int right(int* hp, int p);
void removex(int* hp, int p);
void insert(int *hp, int ele);
int* heapify(int* ar, int sz);
int pop(int* hp);
void push(int* hp, int ele);
void printHeap(int* hp);
bool empty(int* hp);
void heapsort(int* ar, int sz);
