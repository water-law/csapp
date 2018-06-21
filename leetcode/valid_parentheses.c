bool isValid(char* s) {
    int len = strlen(s);
    printf("%d", len);
    char *t = (char *)malloc(sizeof(char) * (len + 1));
    int i, tlen = 0;
    for (i = 0; i < len; i++) {
        if (s[i] == '{' ||s[i] == '[' || s[i] == '(') {
           t[tlen] = s[i]; 
           tlen++;
        }else if (s[i] == '}') {
            printf("A");
            if (t[tlen - 1] != '{') {
                return false;
            }else {
                tlen--;
                t[tlen] = '\0';
            }
        }else if (s[i] == ']') {
            printf("B");
            if (t[tlen - 1] != '[') {
                return false;
            }else {
                tlen--;
                t[tlen] = '\0';
            }
        }else if (s[i] == ')') {
            printf("%d", tlen);
            if (t[tlen - 1] != '(') {
                printf("%c", t[tlen - 1]);
                return false;
            }else {
                tlen--;
                t[tlen] = '\0';
            }
        }
        
    }
    
    if (t[0] == '\0') {
        return true;
    }
    return false;
}
