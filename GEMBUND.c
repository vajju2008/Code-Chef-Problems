#include <stdio.h>

int main() {
    int T;
    
    scanf("%d", &T);
    

    while (T--) {
        
        int R, B, G;
        
        scanf("%d %d %d", &R, &B, &G);
        

        // Maximum bundles possible to gett the Marbles 
        int bundles = R;
        if (B < bundles) bundles = B;
        
        if (G < bundles) bundles = G;
        

       
        int coins = bundles * 10;

        
        int remaining = (R + B + G) - (bundles * 3);
        coins += remaining * 3;

        printf("%d\n", coins);
    }

    return 0;
}
