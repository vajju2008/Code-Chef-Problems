void sort_by_area(struct triangle* tr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double s1 = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
            double area1 = sqrt(s1 * (s1 - tr[i].a) * (s1 - tr[i].b) * (s1 - tr[i].c));

            double s2 = (tr[j].a + tr[j].b + tr[j].c) / 2.0;
            double area2 = sqrt(s2 * (s2 - tr[j].a) * (s2 - tr[j].b) * (s2 - tr[j].c));

            if (area1 > area2) {
                struct triangle temp = tr[i];
                tr[i] = tr[j];
                tr[j] = temp;
            }
        }
    }
}

