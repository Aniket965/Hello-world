#include <stdio.h>
main() {
  long long P = 1,
            E = 2,
            T = 5,
            A = 61,
            L = 251,
            N = 3659,
            R = 271173410,
            G = 1479296389,
            x[] = { G * R * E * E * T , P * L * A * N * E * T };
  puts((char*)x);
}