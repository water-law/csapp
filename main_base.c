#include <stdlib.h>
#include <math.h>
#include <stdio.h>


int big_count(int n) {
    int c = 0;
    n = n - 1;
    while (n > 0) {
        if (n & 1 == 1) {
            ++c; 
        }
        n >>= 1;
    }
    return c;
}

void print_n(int n) {
    int nn = (int)(pow(2, n));
    printf("%d, %d, 0x%x\n", n, nn, nn);
}


void print_n_10(int n) {
    printf("%d, %d, 0x%x\n", big_count(n), n, n);
}

void print_n_16(int n) {
    printf("%d, %d, 0x%x\n", big_count(n), n, n);
}

int main(int argc, char** argv) {
    int n, mode;
    while(scanf("%d", &mode) != EOF) {
        switch (mode) {
            case 1:
                scanf("%d", &n);
                print_n(n);
                break;
            case 2:
                scanf("%d", &n);
                print_n_10(n);
                break;
            case 3:
                scanf("%x", &n);
                print_n_16(n);
                break;
            default:
                break;
        }
    }

    return 0;
}

