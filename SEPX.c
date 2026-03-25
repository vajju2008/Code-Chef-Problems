#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T); // Read number of test cases. Brace yourself, Chef! 🍕

    while (T--) {
        int n, x;
        scanf("%d %d", &n, &x); // Read n and pivot x 

        int l = 0, e = 0, g = 0; // Counters: less, equal, greater
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v); // Read each element

            if (v < x) l++;        // This guy is too small 🙃
            else if (v == x) e++;  // Perfect match 😍
            else g++;              // Too big, flexing 💪
        }

        // If one side is empty OR we found an exact match, Chef is happy
        if (l == 0 || g == 0 || e > 0) {
            printf("Yes\n"); // Party time 🎉
        } else {
            printf("No\n");  // Sorry Chef, not today 😢
        }
    }

    return 0; // Program ends, Chef closes shop 🛑
}
