#include <stdlib.h>
#include <stdio.h>
#include "array_list.h"

List ListInit(int size) {
	List L = malloc(sizeof(List));
	L->table = malloc(size*sizeof(ListItem));
	L->n = 0;
	return L;
}

int ListEmpty(List L) {
	return L->n == 0;
}

int ListLength(List L) {
	return L->n;
}

int ListLocate(ListItem x, List L) {
	int i;
	for (i = 0; i < L->n;i++) {
		if (L->table[i]==x)
			return ++i;
	}
	return 0;
}

int ListItemRetrieve(int k, List L) {

	if (k < 1 || k > L->n) perror("out of bounds");
	return L->table[k - 1];
}

void ListInsert(int k, ListItem x, List L) {
	int i;
	if (k < 0 || k > L->n) perror("out of bounds");
	if (k > L->maxsize) perror("out of memory");
	for (i = L->n - 1; i >= k; i--) {
		L->table[i+1] = L->table[i];
	}
	L->table[k] = x;
	L->n++;
}

ListItem ListDelete(int k, List L) {
	ListItem x;
	int i;
	if (k < 1 || k > L-> n) perror("out of bounds");
	x = L->table[k - 1];
	for (i = k; i < L->n;i++) L->table[i] = L->table[i+1];
	L->n--;
	return x;
}

void PrintList(List L) {
	int i;
	for (i = 0; i < L->n;i++) printf("%d\n", L->table[i]);
}
int main (int argc, char const *argv[]) {
	List L = ListInit(12);
	ListInsert(0, 12, L);
	ListInsert(1, 2323, L);
	PrintList(L);
	return 0;
}
