#include<stdio.h>

#define MOD 10007

int arr[1001];

long long dp(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (arr[n] != 0) return arr[n];
    return arr[n] = (dp(n-1) + dp(n-2)) % MOD;
}

int main() {
    int n;
    scanf("%d", &n);

    
    printf("%lld\n", dp(n));

    return 0;
}
