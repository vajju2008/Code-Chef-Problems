#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N;
        scanf("%d", &N);
        
        int c1 = 0, c2 = 0, c3 = 0;
        
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            if (x == 1) c1++;
            else if (x == 2) c2++;
            else if (x == 3) c3++;
        }
        
        int deletions = 0;
        
        // Handle 1 and 3 conflicts
        if (c1 > 0 && c3 > 0) {
            deletions += (c1 < c3 ? c1 : c3);
        }
        
        // Handle 2 conflitcs
        if (c2 > 1) {
            deletions += (c2 - 1);
        }
        
        printf("%d\n", deletions);
    }
    
    return 0;
}
