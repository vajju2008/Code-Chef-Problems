#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle {
    int a, b, c;
    double area;
};

double triangle_area(int a, int b, int c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int cmp(const void* x, const void* y) {
    struct triangle* t1 = (struct triangle*)x;
    struct triangle* t2 = (struct triangle*)y;
    if (t1->area < t2->area) return -1;
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    struct triangle* arr = malloc(n * sizeof(struct triangle));

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].c);
        arr[i].area = triangle_area(arr[i].a, arr[i].b, arr[i].c);
    }

    qsort(arr, n, sizeof(struct triangle), cmp);

    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", arr[i].a, arr[i].b, arr[i].c);
    }

    return 0;
}

