#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort (Chef sorts pizzas 🍕)
int cmp(const void *a, const void *b) {
    long x = *(long*)a;
    long y = *(long*)b;
    return (x > y) - (x < y);
}

int main() {
    int T;
    scanf("%d", &T); // ⚔️

    while (T--) {
        int n;
        scanf("%d", &n);

        long *a = (long*)malloc(n * sizeof(long));
        for (int i = 0; i < n; i++) {
            scanf("%ld", &a[i]); // collecting  🍕
        }

        
        qsort(a, n, sizeof(long), cmp);

        long *p = (long*)malloc((n + 1) * sizeof(long));
        p[0] = 0;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + a[i - 1];
        }

        long ans = 0;

        
        for (int k = 1; k <= n - 1; k++) {
            long sumK = p[n] - p[n - k]; 
            long avg = (a[0] + sumK) / (k + 1); 
            long d = avg - a[0]; 
            if (d > ans) ans = d; 
        }

        
        for (int k = 1; k <= n - 1; k++) {
            long sumK = p[k]; 
            long avg = (a[n - 1] + sumK) / (k + 1); 
            long d = a[n - 1] - avg; // diffff
            if (d > ans) ans = d; 
        }

        printf("%ld\n", ans); 

        free(a);
        free(p);
    }

    return 0; 
}
