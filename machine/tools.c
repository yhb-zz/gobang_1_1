#include <stdlib.h>
#include "tools.h"

// 快速计算非负整数的非负整数次幂
int rec_pow(int base,int exp) {
    if (base < 0 || exp < 0) {
        perror("base or exp can't bellow zero.");
    }
    if (exp == 0) {
        if (base == 0) {
            perror("base is zero while exp is zero.");
        } else {
            return 1;
        }
    }
    int half = rec_pow(base, exp / 2);
    if (exp % 2) {
        return half * half * base;
    } else {
        return half * half;
    }
}