#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int* b = new int[n];
    
    b[0] = max(0, arr[0]);
    int omax = b[0];
    for (int i = 1; i < n; i++) {
        b[i] = max(b[i - 1] + arr[i], arr[i]);
        omax = max(b[i], omax);
    }
    return omax;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubarraySum(arr, n);

    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}
