/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.cpp
 * Author: zjp
 *
 * Created on May 13, 2018, 2:36 PM
 */

#include <stdlib.h>
#include <stdio.h>

/*
 * 
 */
int main(int argc, char** argv) {
    unsigned long a = 0xffffffff;
    printf("0x%x\n", a); // 0x1111 0001
    a = a << 32;
    printf("0x%x\n", a); // 0x0011 1100
    return 0;
}

