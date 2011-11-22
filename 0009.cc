// http://projecteuler.net/problem=9
//
// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, a² + b² = c²
// For example, 3² + 4² = 9 + 16 = 25 = 5².
// 
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.
//
// Answer: 31875000

#include <cstdio>

void foo(void) {
    for (int i = 1; i < 500; i++) {
        for (int j = 1; j < 500; j++) {
            int k = 1000 - i - j;
            if (i * i + j * j == k * k) {
                printf("%d² + %d² = %d²\n", i, j, k);
                printf("%d * %d * %d = %d\n", i, j, k, i * j * k);
                return;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    foo();
    return 0;
}
