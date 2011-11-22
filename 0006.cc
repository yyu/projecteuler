// http://projecteuler.net/problem=6
//
// The sum of the squares of the first ten natural numbers is,
// 1² + 2² + ... + 10² = 385
//
// The square of the sum of the first ten natural numbers is,
// (1 + 2 + ... + 10)² = 55² = 3025
//
// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
//
// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
// 
// Answer: 25164150

#include <iostream>

int calc(int n) {
    int sum = 0;
    int m = (n * (n + 1)) >> 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            sum += m - i;
    return sum;
}

void test(int n) {
    std::cout << n << " : " << calc(n) << "\n";
}

int main(int argc, char* argv[]) {
    test(10);
    test(100);
    return 0;
}
