// http://projecteuler.net/problem=7
//
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// What is the 10 001st prime number?
//
// Answer: 104743

#include <iostream>
#include <vector>

#include <cstdio>
#include <cassert>

bool is_prime(std::vector<int>& primes, int x) {
    int n = primes.size();
    for (int i = 0; i < n; i++) {
        int d = primes[i];
        if (x % d == 0)
            return false;
        if (d * d > x)
            return true;
    }
    assert(0);  // should never arrive here if called by get_prime()
}

int get_prime(int idx) {
    std::vector<int> primes;
    primes.push_back(2);
    for (int n = primes.size(); n < idx; n++) {
        // append more to primes array
        int k = primes[n - 1] + 1;
        while (!is_prime(primes, k))
            k++;
        primes.push_back(k);
    }
    return primes[idx - 1];
}

void test(int idx) {
    printf("%7d : %7d\n", idx, get_prime(idx));
}

int main(int argc, char* argv[]) {
    for (int i = 1; i <= 20; i++)
        test(i);
    test(10001);
    return 0;
}
