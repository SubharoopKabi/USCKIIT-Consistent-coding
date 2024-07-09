#include <iostream>
#include <algorithm>

int trappingWater(int arr[], int n) {
    int ans = 0;
    int l[100], r[100];
    l[0] = arr[0];
    r[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++) {
        l[i] = std::max(arr[i], l[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        r[i] = std::max(arr[i], r[i + 1]);
    }

    for (int i = 1; i < n - 1; i++) {
        ans += std::max(0, std::min(l[i], r[i]) - arr[i]);
    }
    return ans;
}

int main() {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = trappingWater(arr, n);

    std::cout << "Total water trapped: " << result << std::endl;

    return 0;
}
