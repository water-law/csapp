#include <stdio.h>
#include <stdlib.h>
#include "point_list.h"

link NewNode(){
   link p;
   if ((p = malloc(sizeof(Node))) == 0){
       perror("Exhaustd memory.");
   }else{
       return p;   
   }

}

List ListInit(){
    List L = malloc(sizeof(Llist));
    L->first = 0;
    return L;
}

int ListEmpty(List L){
    return L->first == 0;
}

int ListLength(List L){
    int len = 0;
    link p = L->first;
    while (p){
        len++;
	    p = p->next;
    }
    return len;
}

ListItem ListRetrieve(int k, List L){
    int i;
    link p;
    if (k < 1) {
       perror("out of bounds");
    }
    p = L->first;i = 1;
    if (p == 0) {
        perror("segment fault");
    }
    while(i < k && p){
        p = p->next;
	    i++;
    }
    return p->element;
}

int ListLocate(ListItem x, List L){
    int i = 1;
    link p = L->first;
    while (p && p->element != x) {
        p = p->next;
        i++;
    }
    return p ? i : 0;
}

void ListInsert(int k, ListItem x, List L) {
    int i = 1;
    link p, node;
    if (k < 0) {
        perror("out of bounds");
    }
    p = L->first;
    while (p && i < k) {
        p = p->next;
        i++;
    }
    node = NewNode();
    node->element = x;
    if (!k) {
        node->next = L->first;
        L->first = node;
    }else {
        node->next = p->next;
        p->next = node;
    }
}

ListItem ListDelete(int k, List L) {
    int i = 1;
    ListItem x;
    link p, q;
    if (k < 1 || L->first) {
        perror("out of bounds");
    }
    p = L->first;
    if (k == 1) {
        L->first = p->next;
    }else {
        q = L->first;
        while (q && i < k - 1) {
            q = q->next;
            i++;
        }
        p = q->next;
        q->next = p->next;
    }
    x = p->element;
    free(p);
    return x;
}

void PrintList(List L) {
    link p = L->first;
    while (p) {
        printf("%d\n", p->element);
        p = p->next;
    }
}

int main(int argc, char const *argv[]){
    List L = ListInit();	
    printf("%d\n", ListEmpty(L));
    ListInsert(0, 12, L);
    ListInsert(1, 112, L);
    printf("%d\n", ListRetrieve(1, L));
    printf("%d\n", ListLocate(12, L));
    printf("%d\n", ListDelete(1, L));
    PrintList(L);
    return 0;
}
