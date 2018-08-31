#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_SIZE 10000


int *getNext(char *target) {
    int t_len = strlen(target);
    int *next = (int *)malloc(sizeof(int) * t_len);
    // source: abcdabrdfd
    // target: abcdabx
    //             abcdabx
    // next[j] = k, when source[i] != target[j]
    // we have target[0:k-1] = target[j-k,j-1]
    next[0] = -1;
    int j = 0;
    int k = -1;
    while(j < t_len - 1) {
        if(k == -1 || target[j] == target[k]) {
        // if target[k] = target[j]:
        // next[j]-> target[0:k-1] = target[j-k,j-1] and target[k] = target[j]
        // we have target[0:k] = target[j-k,j] -> next[j+1] = k + 1 = next[j] + 1
            next[++j] = ++k;
        }else {
            k = next[k];
        }
    }

    return next;
}

int pattern(char *source, char *target) {
    int s_len = strlen(source), t_len = strlen(target);
    printf("source str length is %d\ntarget str length is %d\n", s_len, t_len);
    int i = 0;
    int j = 0;
    int *next = getNext(target);
    int *p = next;
    for (i = 0; i < t_len; i++) {
        printf("%d", *(p + i));
    }
    return 0;
    while(i < s_len && j < t_len) {
        if (j == -1 || source[i] == target[j]) {
            i++;
            j++;
        }else {
            j = next[j];
        }
    }
    if (j == t_len) {
        return i - j;
    }else {
        return -1;
    }
}

int main(int argv, const char *argc[]) {
    int pos;
    char tstr[MAX_SIZE], pstr[100];
    scanf("%s%s", tstr, pstr);
    pos = pattern(tstr, pstr);
    printf("%d\n", pos);
    return 0;
}