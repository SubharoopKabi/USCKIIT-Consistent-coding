#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;

int countDistinctSubsequences(string inputString) {
    int length = inputString.size();
    vector<long long> dpArray(length + 1, 0);  
    unordered_map<char, int> lastOccurrence;  

    dpArray[0] = 1;

    for (int i = 1; i <= length; ++i) {
        dpArray[i] = (2 * dpArray[i - 1]) % MOD;

        char currentChar = inputString[i - 1];
        if (lastOccurrence.find(currentChar) != lastOccurrence.end()) {
            dpArray[i] = (dpArray[i] - dpArray[lastOccurrence[currentChar] - 1] + MOD) % MOD;
        }

        lastOccurrence[currentChar] = i;
    }

    return (dpArray[length] - 1 + MOD) % MOD; 
}

int main() {
    string inputString = "abc";
    cout << "Number of distinct non-empty subsequences: " << countDistinctSubsequences(inputString) << endl;

    return 0;
}
