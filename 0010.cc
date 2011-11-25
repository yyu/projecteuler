// http://projecteuler.net/problem=10
//
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.
//
// Answer: 142913828922

#include <iostream>
#include <vector>

#include <cstdio>
#include <cmath>
#include <cassert>

class Prime {
public:
    Prime(long long N) : current_(2) {
        // make sure there's at least one prime after A_[N - 1]
        N += static_cast<long long>(sqrt(N + 1.0)) + 1;

        for (long long i = 0; i < N; i++)
            A_.push_back(i);
        for (long long i = 2; i * i <= N; i++) {
            if (A_[i] == 0)
                continue;
            for (long long j = i * 2; j < N; j += i)
                A_[j] = 0;
        }
    }
    long long operator*() {
        return A_[current_];
    }
    void inc() {
        do {
            ++current_;
        } while (A_[current_] == 0);
        assert(current_ < A_.size());
    }
    void operator++() {
        inc();
    }
    void operator++(int) {
        inc();
    }
private:
    std::vector<long long> A_;
    long long current_;
};

void test(int n) {
    long long sum = 0;
    for (Prime p(n); *p < n; p++)
        sum += *p;
    std::cout << n << " : " << sum << "\n";
}

int main(int argc, char* argv[]) {
    //test(10);
    test(2000000);
    return 0;
}
