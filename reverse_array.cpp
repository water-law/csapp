#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void inplace_swap(int *x , int *y) {
    if (*x == *y) {
        return;
    }
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}


void reverse_array(int a[], int cnt) {
    int f, l;
    for (f = 0, l= cnt - 1; f <= l; f++, l--) {
        inplace_swap(&a[f], &a[l]);
    }
    
}                                                                                                                                        
//int main(int argc, char** argv) {
//    int a[] = {1, 2, 3, 4, 5};
//    int len = sizeof(a) / sizeof(int);
//    reverse_array(a, len);
//    for (int i = 0 ; i < len; i++) {
//        printf("%d ", a[i]);
//    }
//    return 0;
//}

