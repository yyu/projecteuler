// http://projecteuler.net/problem=4
//
// A palindromic number reads the same both ways. The largest palindrome made
// from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.
//
// Answer: 906609

#include <iostream>
#include <cstdio>

bool ispalin(int x) {
    int y = x;
    int r = 0;
    while (y) {
        r = r * 10 + y % 10;
        y /= 10;
    }
    return r == x;
}

int main(int argc, char* argv[]) {
    int _cnt_ = 0;
    int largest = 1;
    for (int k = 999; k > 30; k--) {
        int flag = false;
        for (int i = 999, j = k; j <= i; i--, j++) {
            ++_cnt_;
            int x = i * j;
            if (x > largest) {
                flag = true;
                if (ispalin(x)) {
                    printf("%d: %d * %d\n", x, i, j);
                    largest = x;
                }
            }
        }
        if (!flag)  // no more product is larger than largest, so we know
            break;  // we're done
    }
    printf("%d \033[37m(cost: %d compares)\033[0m\n", largest, _cnt_);
    return 0;
}
