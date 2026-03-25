#include <iostream>
using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    if (N >= 2*X && N >= 2*Y)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
 