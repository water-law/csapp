int romanToInt(char* s) {
    int i, len = strlen(s);
    int total = 0;
    for (i = 0; i < len; i++) {
        char c = s[i];
        printf("%c\n", c);
        if ('I' == c) {
            if (i + 1 <= len) {
                if ('V' == s[i + 1]) {
                    i++;
                    total += 4;
                }else if('X' == s[i + 1]) {
                    i++;
                    total += 9;
                }else total += 1;
            }
        }else if ('V' == c) {
            total += 5;
        }else if ('X' == c) {
            if (i + 1 <= len) {
                if ('L' == s[i + 1]) {
                    i++;
                    total += 40;
                }else if('C' == s[i + 1]) {
                    i++;
                    total += 90;
                }else total += 10;
            }
        }else if ('L' == c) {
            total += 50;
        }else if ('C' == c) {
            if (i + 1 <= len) {
                if ('D' == s[i + 1]) {
                    i++;
                    total += 400;
                }else if('M' == s[i + 1]) {
                    i++;
                    total += 900;
                }else total += 100;
            }
        }else if ('D' == c) {
            total += 500;
        }else if ('M' == c) {
            total += 1000;
        }
    }
    return total;
}
