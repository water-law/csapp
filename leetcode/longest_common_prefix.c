char* longestCommonPrefix(char** strs, int strsSize) {
    int i, j, rlen = 0, flag = 0;
    if (strsSize == 1) {
        return *strs;
    }
    char *first = *strs;
    char *p = *strs;
    int len = strlen(first);
    for (i = 0; i < len; i++) {
        if (flag == 1) {
            break;
        }
        for (j = 1; j < strsSize; j++) {
            if ((*(strs + j))[i] != first[i]) {
                flag = 1;
                break;
            }
        }
        if (j == strsSize) {
            printf("%d\n", i);
            rlen ++;
        }
    }
    printf("%d", rlen);
    char* subch=(char*)calloc(sizeof(char),rlen+1);
    if (rlen == 0) {
    }
    for (i = 0; i < rlen; i++) {
        subch[i] = first[i];
    }
    subch[rlen] = '\0';
    return subch;
}
