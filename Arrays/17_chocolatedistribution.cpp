#include <iostream>
#include <vector>
#include <algorithm>

long long findMinDiff(std::vector<long long> a, long long n, long long m) {
    std::sort(a.begin(), a.end());
    long long ans = a[m - 1] - a[0];
    for (int i = 1; i < n - m + 1; i++) {
        ans = std::min(a[i + m - 1] - a[i], ans);
    }
    return ans;
}

int main() {
    std::vector<long long> a = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    long long n = a.size();
    long long m = 7;
    
    long long result = findMinDiff(a, n, m);
    
    std::cout << "Minimum difference is: " << result << std::endl;
    
    return 0;
}
