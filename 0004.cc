// http://projecteuler.net/problem=4
//
// A palindromic number reads the same both ways. The largest palindrome made
// from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.
//
// Answer: 906609

#include <iostream>
#include <cstdio>

bool ispalin(char* s, int n) {
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i])
            return false;
    }
    return true;
}

bool ispalin(int x) {
    char s[8];
    int n = sprintf(s, "%d", x);
    return ispalin(s, n);
}

int main(int argc, char* argv[]) {
    int _cnt_ = 0;
    int largest = 1;
    for (int k = 999; k > 30; k--) {
        for (int i = 999, j = k; j < 1000; i--, j++) {
            ++_cnt_;
            int x = i * j;
            if (x > largest && ispalin(x)) {
                printf("%d: %d * %d\n", x, i, j);
                largest = x;
            }
        }
    }
    printf("%d \033[37m(cost: %d compares)\033[0m\n", largest, _cnt_);
    return 0;
}
