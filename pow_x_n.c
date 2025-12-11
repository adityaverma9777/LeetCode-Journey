#include <stdio.h>

double myPow(double x, int n) {
    if (n == 0) return 1.0;
    if (x == 0) return 0.0;
    
    long long N = n;
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    
    double result = 1.0;
    double current = x;
    
    while (N > 0) {
        if (N % 2 == 1) result *= current;
        current *= current;
        N /= 2;
    }
    
    return result;
}
