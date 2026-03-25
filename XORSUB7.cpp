#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct NumberInfo {
    int value;
    int bitCount;
};

int countSetBits(int n) {
    return __builtin_popcount(n);
    
}

void solve() {
    int arraySize;
    if (!(cin >> arraySize)) return;

    vector<int> inputNumbers(arraySize);
    
    for (int i = 0; i < arraySize; ++i) {
        
        cin >> inputNumbers[i];
    }

    vector<NumberInfo> numbers;
    
    numbers.reserve(arraySize);

    for (int num : inputNumbers) {
        numbers.push_back({num, countSetBits(num)});
        
    }

    sort(numbers.begin(), numbers.end(), [](const NumberInfo& a, const NumberInfo& b) {
        
        if (a.bitCount != b.bitCount) {
            
            return a.bitCount < b.bitCount;
        }
        return a.value < b.value;
        
    });

    vector<int> chainLength(arraySize, 1);
    
    int maxChainFound = 1;

    for (int i = 0; i < arraySize; ++i) {
        
        for (int j = 0; j < i; ++j) {
            
            if ((numbers[j].value & numbers[i].value) == numbers[j].value) {
                
                chainLength[i] = max(chainLength[i], chainLength[j] + 1);
                
            }
        }
        maxChainFound = max(maxChainFound, chainLength[i]);
    }

    cout << maxChainFound << endl;
    
}


int main() {
    
    ios::sync_with_stdio(false);
    
    cin.tie(nullptr);
    
    
    

    int testCases;
    
    if (cin >> testCases) {
        
        while (testCases--) {
            
            solve();
            
        }
    }
    return 0;
}