#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    int n;
    int *bit;
} Fenwick;

Fenwick *fenwick_create(int n) {
    Fenwick *f = (Fenwick*)malloc(sizeof(Fenwick));
    f->n = n;
    f->bit = (int*)calloc(n + 1, sizeof(int));
    return f;
}

void fenwick_free(Fenwick *f) {
    if (!f) return;
    free(f->bit);
    free(f);
}

void fenwick_add(Fenwick *f, int idx, int delta) {
    while (idx <= f->n) {
        f->bit[idx] += delta;
        idx += idx & -idx;
    }
}

int fenwick_sum(Fenwick *f, int idx) {
    int s = 0;
    while (idx > 0) {
        s += f->bit[idx];
        idx -= idx & -idx;
    }
    return s;
}

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    

    while (T--) {
        
        int n;
        
        scanf("%d", &n);
        

        int *perm = (int*)malloc((n + 1) * sizeof(int));
        
        int *pos  = (int*)malloc((n + 1) * sizeof(int));
        

        for (int i = 1; i <= n; ++i) {
            int x;
            
            scanf("%d", &x);
            
            perm[i] = x;
            
            pos[x] = i;
            
        }

        Fenwick *fw = fenwick_create(n);

        
        for (int i = 1; i <= n; ++i)
            fenwick_add(fw, i, 1);

        ll total = 0;
        int alive = n;

        for (int val = n; val >= 1; --val) {
            int p = pos[val]; 
            int left_alive = fenwick_sum(fw, p - 1);
            int right_alive = alive - left_alive - 1;
            total += (left_alive < right_alive ? left_alive : right_alive);
            fenwick_add(fw, p, -1); 
            --alive;
        }

        printf("%lld\n", total);

        fenwick_free(fw);  
        
        free(perm);
        
        free(pos);
        
    }

    return 0;
}
