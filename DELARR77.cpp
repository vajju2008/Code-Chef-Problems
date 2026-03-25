#include <iostream>
#include <algorithm>
using namespace std;

static int memo[110][110][110];
static int val[110], cost[110];
int sizeN;

const int BIG = 1000000000;

void process() {
    cin >> sizeN;

    for (int i = 1; i <= sizeN; i++) cin >> val[i];
    for (int i = 1; i <= sizeN; i++) cin >> cost[i];

    for (int l = 1; l <= sizeN + 1; l++) {
        for (int used = 0; used <= sizeN; used++) {
            memo[l][l - 1][used] = 0;
        }
    }

    for (int length = 1; length <= sizeN; length++) {
        for (int start = 1; start + length - 1 <= sizeN; start++) {
            int end = start + length - 1;

            for (int taken = 0; taken < start; taken++) {
                int bestAns = BIG;

                for (int mid = start; mid <= end; mid++) {
                    int current = val[mid] * cost[taken + 1];
                    int leftCost = memo[start][mid - 1][taken];

                    int rightA = memo[mid + 1][end][taken + 1];
                    int rightB = memo[mid + 1][end][taken + 1 + (mid - start)];

                    bestAns = min(bestAns, current + leftCost + min(rightA, rightB));
                }

                memo[start][end][taken] = bestAns;
            }
        }
    }

    cout << memo[1][sizeN][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tests;
    cin >> tests;
    while (tests--) {
        process();
    }
    return 0;
}
