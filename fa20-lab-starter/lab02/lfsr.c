#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    /*
    通过get取得0235位，然后按位异或，得到新的最高位
    然后把原16位数右移，与新最高位左移15位进行相加。
    */
   unsigned reg_0 = !!(*reg & (1<<0));
   unsigned reg_2 = !!(*reg & (1<<2));
   unsigned reg_3 = !!(*reg & (1<<3));
   unsigned reg_5 = !!(*reg & (1<<5));
   unsigned msb = reg_0 ^ reg_2 ^ reg_3 ^ reg_5;
   *reg = *reg >> 1;
   *reg = *reg + (msb << 15);
}

