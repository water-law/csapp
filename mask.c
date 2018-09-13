#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int set_zero(int x) {
    int r = x & 0xFF;
    printf("0x%x\n", r);
    return r;
}


int set_reverse(int x) {
    int r = x ^ ~0xFF;
    printf("0x%x\n", r);
    return r;
}

int set_last_byte(int x) {
    int r = x | 0xFF;
    printf("0x%x\n", r);
    return r;
}

int equal(int x, int y) {
    return !(x ^ y);
}

int main(int argc, char** argv) {
//    int w, x;
//    while (scanf("%x", &x) != EOF) {
//        set_zero(x);
//        set_reverse(x);
//        set_last_byte(x);
//    }

    int x = 0x66, y = 0x66;
    int res = equal(x, y);
    if (res) {
        printf("x is equal to y\n");
    } else {
        printf("x is not equal to y\n");
    }
    printf("x & y = 0x%x\n", x & y);
    printf("x | y = 0x%x\n", x | y);
    printf("~x | ~y = 0x%x\n", ~x | ~y);
    printf("x & !y = 0x%x\n", x & !y);
    printf("x && y = 0x%x\n", x && y);
    printf("x || y = 0x%x\n", x || y);
    printf("!x || !y = 0x%x\n", !x || !y);
    printf("x && ~y = 0x%x\n", x && ~y);
    return 0;
}

