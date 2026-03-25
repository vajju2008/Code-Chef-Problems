#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, m, b;
    cin >> n >> a >> m >> b;

    long long totalExpense = 1LL * n * a;
    long long totalIncome = 1LL * m * b;

    long long result = totalIncome - totalExpense;
    cout << result;

    return 0;
}
