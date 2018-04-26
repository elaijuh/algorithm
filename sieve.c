#include <stdio.h>
#include <string.h>

// O(n loglog n)
void eratosthenes_sieve(int n) {
    int i, j;
    int flag[200];
    memset(flag, 0, sizeof(flag));
    for (i = 2; i * i <= n; i++) {
        if (!flag[i]) {
            for (j = i * i; j <= n; j+=i) {
                flag[j] = 1;
            }
        }

    }
    for (int i = 2; i <= n; i++) {
        if (!flag[i]) {
            printf("%d ", i);
        }
    }
}

// O(n)
void euler_sieve(int n) {
    int i, j, k = 0;
    int flag[200];
    int prime[200];
    memset(flag, 0, sizeof(flag));
    for (i = 2; i < n; i++) {
        if (!flag[i]) {
            prime[k++] = i;
        }
        for (j = 0; i * prime[j] <= n; j++) {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }

    }
    for (int i = 0; i < k; i++) {
        printf("%d ", prime[i]);
    }
}

int main(void) {
    eratosthenes_sieve(100);
    printf("\n");
    euler_sieve(100);
}
