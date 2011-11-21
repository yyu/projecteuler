// http://projecteuler.net/problem=3
//
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143?
//
// Answer: 6857

#include <iostream>
#include <set>

bool is_prime(long long n) {
    for (long long k = 2; k * k <= n; k++)
        if (n % k == 0)
            return false;
    return true;
}

long long get_next_prime(long long x) {
    long long k = x + 1;
    while (!is_prime(k))
        k++;
    return k;
}

long long lpf(long long n) {
    long long largest = 1;
    for (long long prime = 2; prime <= n; prime = get_next_prime(prime)) {
        if (n % prime == 0) {
            while (n % prime == 0)
                n /= prime;
            if (prime > largest)
                largest = prime;
        }
    }
    return largest;
}

long long stupid_lpf(long long n) {
    long long largest = 1;
    for (long long k = 2; k <= n / 2; k++) {
        if ((k & 0xFFFFFF) == 0)
            std::cerr << '.';
        if (is_prime(k) && (n % k == 0))
            largest = k;
    }
    return largest;
}

long long orange_lpf(long long n) {
    long long q = n;
    for (long long i = 2; i * i <= q;) {
        if (q % i == 0)
            q /= i;
        else
            i++;
    }
    return q;
}

void test(long long n) {
    // std::cout << n << " : " << stupid_lpf(n) << "\n";
    //std::cout << n << " : " << lpf(n) << "\n";
    std::cout << "\033[31m" << n << " : " << orange_lpf(n) << "\033[0m\n";
}

int main(int argc, char* argv[]) {
    //test(13195);
    test(600851475143);
    //test(337500);
    return 0;
}
