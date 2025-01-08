#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,
                 unsigned n) {
    // YOUR CODE HERE
    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns 
    // 0 or 1)
    //step1: 创造000000000001000000....，1处于第n位
    //step2:将该数与x按位与，return
    unsigned y = 1 << n;
    //if (x & y) {
    //    return 1;
    //} else {
    //    return 0;
    //}
    //上面用到了条件语句
    return !!(x & y);
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {
    // YOUR CODE HERE
    //思路：把x右移n+1位，左移1位，+v，再左移n位，+之前右移n+1位除去的内容
    /** unsigned r = *x - ((*x)>> (n+1))<<(n+1);
        *x = *x >> n+1;
        *x = *x << 1;
        *x += v;
        *x = *x << n;
        *x += r;
    */
    //首先将x的第n位置零
    *x =(*x & ~ (1<< n)) | (v << n);
}
// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,
              unsigned n) {
    // YOUR CODE HERE
    //大聪明写法
    //unsigned not_nth_bit =  !(*x & (1 << n));
    //*x = (*x & ~ (1<< n)) | (not_nth_bit << n);
    //小聪明写法
    *x ^= (1 << n);
    
}

