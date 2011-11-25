// http://projecteuler.net/problem=10
//
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.
//
// Answer: 

#include <iostream>
#include <vector>
#include <cstdio>
#include <cassert>

namespace {
int _A[] = {2};
std::vector<int> A(_A, _A + 1);
bool is_prime(int x) {
    int i = 0;
    while (A[i] * A[i] <= x) {
        if (x % A[i] == 0)
            return false;
        i++;
    }
    return true;
}
int get_next_prime(int x) {
    assert(x == *A.rbegin());
    int i = x + 1;
    while (!is_prime(i))
        i++;
    A.push_back(i);
    return i;
}
}

void test(int n) {
    long long sum = 0;
    int prime = 2;
    while (prime < n) {
        sum += prime;
        prime = get_next_prime(prime);
    }
    std::cout << n << " : " << sum << "\n";
}

int main(int argc, char* argv[]) {
    test(2000000);
    return 0;
}
