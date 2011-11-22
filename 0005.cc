// http://projecteuler.net/problem=5
//
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
//
// Answer: 232792560

#include <iostream>
#include <cassert>

int main(int argc, char* argv[]) {
    int x = 2520 * 11 * 13 * 17 * 19 * 2;
    std::cout << x << "\n";
    for (int i = 1; i <= 20; i++)
        assert(x % i == 0);
    return 0;
}

