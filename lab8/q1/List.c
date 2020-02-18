#include "List.h"

List createList(Student studArray, int arraySize) {
	List l = myalloc(sizeof(struct list));
	l->count = arraySize;
	Node prev = NULL;
	for(int i = 0; i < arraySize; i++) {
		Node n = (Node)myalloc(sizeof(struct node));
		if(i == 0)
			l->first = n;
		else if(i == arraySize-1) {
			l->last = n;
			n->next = NULL;
			prev->next = n;
		}
		else
			prev->next = n;
		prev = n;
		n->record = (Student)myalloc(sizeof(struct student));
		n->record->name = (char *)myalloc(1+strlen(studArray[i].name));
		strcpy(n->record->name, studArray[i].name);
		n->record->marks = studArray[i].marks;
	}
	return l;
}

void insertInOrder(List list, Node newNode){
	Node h = list->first;
	Node prev = h;
	int ct = 0;
	while(h != NULL) {
		if(h->record->marks >= newNode->record->marks) {
			if(ct == 0) {
				list->first = newNode;
				newNode->next = h;
			}
			else {					
				prev->next = newNode;
				newNode->next = h;
			}
			list->count++;
			return;
		}
		ct++;
		prev = h;
		h = h->next;
	}
	if(ct == list->count){
		prev->next = newNode;
		newNode->next = NULL;
		list->last = newNode;
		list->count++;
	}
}

List insertionSort(List list){
	if(list->count == 1)
		return list;
	List l1 = (List)myalloc(sizeof(struct list));
	l1->count = list->count-1;
	int ct = 0;
	Node cur = list->first;
	Node prev = NULL;
	while(ct < l1->count) {
		Node n = (Node)myalloc(sizeof(struct node));
		n->record = (Student)myalloc(sizeof(struct node));
		n->record->name = (char*)myalloc(1+strlen(cur->record->name));
		strcpy(n->record->name, cur->record->name);
		n->record->marks = cur->record->marks;
		if(ct == 0) {
			l1->first = n;
		}
		else if(ct == l1->count-2) {
			l1->last = n;
			n->next = NULL;
			prev->next = n; 
		}
		else {
			prev->next = n;
		}
		prev = n;
		ct++;
		cur = cur->next;
	}
	Node n = (Node)myalloc(sizeof(struct node));
	n->record = (Student)myalloc(sizeof(struct node));
	n->record->name = (char*)myalloc(1+strlen(cur->record->name));
	strcpy(n->record->name, cur->record->name);
	n->record->marks = cur->record->marks;
	l1 = insertionSort(l1);
	insertInOrder(l1, n);
	//printList(l1);
	//printf("\n");
	return l1;
}

double measureSortingTime(List list){

}

void * myalloc(int size){
	globalCounter += size;
	void* tmp = malloc(size+4);
	int* t = (int*)tmp;
	t[0] = size;
	// void * tmp = malloc(size);
	return tmp+4;
}

void myfree(void* ptr) {
	int sz = *((int*)(ptr-4));
	globalCounter -= sz;
	free(ptr);
}
void printList(List list)
{
	Node temp = list->first;
	while(temp!=NULL)
	{
		printf("Name: %s, Marks: %f\n", temp->record->name, temp->record->marks);
		temp=temp->next;
	}

	return;
}
