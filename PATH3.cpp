#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        
        if (N == 2) {
            cout << "-1\n";
            continue;
        }
        
        // N >= 3
        vector<vector<int>> grid(N, vector<int>(N, 0));
        

        for (int j = 0; j < 3; j++) {
            grid[0][j] = 1;
        }
        grid[1][1] = 1;
        grid[1][2] = 1;
        grid[2][1] = 1;
        grid[2][2] = 1;
        
        // Extend right on row 3 (index 2) to the end
        for (int j = 3; j < N; j++) {
            grid[2][j] = 1;
        }
        
        // Extend down on the right column from row 4 (index 3) to end
        for (int i = 3; i < N; i++) {
            grid[i][N-1] = 1;
        }
        
        // Prints the answer or the's outpura
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid[i][j];
                if (j < N-1) cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}