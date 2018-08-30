#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10000

int pattern(char *source, char *target) {
    int s_len = strlen(source), t_len = strlen(target);
    printf("source str length is %d\ntarget str len is %d\n", s_len, t_len);
//    int eq = (source[s_len] == '\0');
//    printf("%d\n", eq);
    if (s_len < t_len) {
        return -1;
    }
    if (s_len == t_len) {
        return strcmp(source, target) == 0 ? 0: -1;
    }
    /**
    source: rerejhnbfngfhijh
    target: rerejsd
    对 source 从 0->0+t_len, 比较各个字符， 若有一个不符， 则从 1->1+t_len重新比较
    **/
    for (int i = 0; i < s_len - t_len + 1; i++) {
        int j;
        for (j = 0; j < t_len; j++) {
            if (source[i+j] != target[j]) {
            // 存在k, 使得 target[0 ~ k-1] == source[i+j-k ~ i+j-1]
                break;
            }
        }
        if (j == t_len) {
            return i;
        }
    }
    return -1;
}


int main(int argv, const char *argc[]) {
    int pos;
    char tstr[MAX_SIZE], pstr[100];
    scanf("%s%s", tstr, pstr);
    pos = pattern(tstr, pstr);
    printf("%d\n", pos);
    return 0;
}