// http://projecteuler.net/problem=3
//
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143?

#include <iostream>
#include <set>

bool is_prime(long long n) {
    for (long long k = 2; k * k <= n; k++)
        if (n % k == 0)
            return false;
    std::cerr << "found prime " << n << "\n";
    return true;
}

void remove_factor(long long& n, long long k) {
    std::cout << "factor " << k << "\n";
    while (n % k == 0)
        n /= k;
}

long long lpf_so_far(long long& n, long long k) {
    long long m = n / k;
    remove_factor(n, k);
    if (is_prime(m)) {
        remove_factor(n, m);
        if (m > k)
            return m;
    }
    return k;
}

long long find_next_factor(long long& n) {
    static std::set<long long> primes;
    for (std::set<long long>::iterator it = primes.begin();
         it != primes.end(); ++it) {
        if (n % *it == 0)
            return lpf_so_far(n, *it);
    }
    long long k = primes.empty() ? 2 : (*primes.rbegin() + 1);
    for (; k * k <= n; k++) {
        if (is_prime(k)) {
            primes.insert(k);
            if (n % k == 0)
                return lpf_so_far(n, k);
        }
    }
    return n;
}

long long lpf(long long n) {
    long long largest = 1;
    while (1) {
        long long p = find_next_factor(n);
        std::cerr << p << ',' << n << '\n';
        if (p <= largest)
            break;
        if (p > largest)
            largest = p;
    }
    return std::max(largest, n);
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
    std::cout << n << " : " << lpf(n) << "\n";
    std::cout << "\033[31m" << n << " : " << orange_lpf(n) << "\033[0m\n";
}

int main(int argc, char* argv[]) {
    test(13195);
    test(600851475143);
    test(337500);
    return 0;
}
