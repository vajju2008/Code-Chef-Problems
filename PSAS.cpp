#include <iostream>

#include <vector>

using namespace std;

void run_test_case() {
    int n_size;
    if (!(cin >> n_size)) return;

    vector<int> nums(n_size);
    for (int k = 0; k < n_size; ++k) {
        cin >> nums[k];
    }

    bool possible = false;


    for (int i = 0; i < n_size; ++i) {
        int current_val = nums[i];
        bool match = true;

        for (int j = 0; j < n_size; ++j) {
            if (j < i) {
                // Preceding elements must cancel out to 0 (must be -current_val)
                if (nums[j] != -current_val) {
                    match = false;
                    break;
                }
            } else if (j > i) {
                // Succeeding elements must reduce to 0 (must be current_val)
                if (nums[j] != current_val) {
                    match = false;
                    break;
                }
            }
        }

        if (match) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t_cases;
    if (cin >> t_cases) {
        while (t_cases--) {
            run_test_case();
        }
    }
    return 0;
}