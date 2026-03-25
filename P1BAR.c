#include <stdio.h>

int main() {
    
    int X, Y;
    
    
    if (scanf("%d %d", &X, &Y) != 2) {
       
        return 1; 
    }
   
    int total_score = (X * 3) + (Y * 2);
    
    
    printf("%d\n", total_score);
    
    return 0; 
}