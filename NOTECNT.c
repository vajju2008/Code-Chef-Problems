#include <stdio.h>

int main(void) {
    int A, B;

   
    scanf("%d %d", &A, &B);

  
    int total_lines = A * B * 100;

    printf("%d\n", total_lines);

    return 0; // total no of pages in a book both froont and back 100
}