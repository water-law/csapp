#include "point_list.h"
#include <stdio.h>
#include <stdlib.h>

link NewNode(){
   link p;
   if ((p = malloc(sizeof(Node))) == 0){
       perror("Exhaustd memory.");
   }else{
       return p;   
   }

}

List ListInit(){
    List L = malloc(sizeof(*L));
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


int main(){
    List L = ListInit();	
    printf("%d", ListEmpty(L));
    printf("%d", ListRetrieve(0, L));
    return 0;
}
