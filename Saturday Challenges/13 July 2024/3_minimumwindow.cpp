#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";
    unordered_map<char, int> tCount;
    for (char c : t) tCount[c]++;
    int start = 0, minLen = INT_MAX, minStart = 0;
    int left = 0, right = 0, formed = 0;
    int required = tCount.size();

    unordered_map<char, int> windowCount;

    while (right < s.size()) {
        char c = s[right];
        windowCount[c]++;
        
        if (tCount.find(c) != tCount.end() && windowCount[c] == tCount[c]) {
            formed++;
        }

        while (left <= right && formed == required) {
            c = s[left];
            
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            windowCount[c]--;
            if (tCount.find(c) != tCount.end() && windowCount[c] < tCount[c]) {
                formed--;
            }
            left++;
        }
        right++;
    }

    return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
}
int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum window substring: " << minWindow(s, t) << endl;

    return 0;
}
