#include <stdio.h>
#define ll long long
 
#ifndef ONLINE_JUDGE
    #define gc getchar
#else
    #define gc getchar_unlocked
#endif
 
int read_int() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    int ret = 0;
    int neg = 1;
    if (c == '-') {
        neg = -1;
        c = gc();
    }
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg*ret;
}
 
int A[100000];
 
int main() {
    int N, min, max, i, K; ll res;
 
    scanf("%d %d\n", &N, &K);
    if (K == 0) {
        for(i=0;i<N;i++)
            printf("%d ", read_int());
    } else if (K%2 == 0) {
        A[0] = read_int();
        min = A[0];
        for(i=1;i<N;i++) {
            A[i] = read_int();
            if (A[i] < min)
                min = A[i];
        }
        for(i=0;i<N;i++) {
            res = (ll)(A[i])-min;
            printf("%llu ", res);
        }
    } else {
        A[0] = read_int();
        max = A[0];
        for(i=1;i<N;i++) {
            A[i] = read_int();
            if (A[i] > max)
                max = A[i];
        }
        for(i=0;i<N;i++) {
            res = (ll)(max)-A[i];
            printf("%llu ", res);
        }
    }
 
    return 0;
}
 
