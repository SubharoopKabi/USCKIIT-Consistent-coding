#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
    if (n == 1) return 0;
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];

    for (int i = 0;i < n;i++) {
        if (arr[i] < k) continue;     // to avoid negative height in curr_min
        int curr_min = min(arr[0] + k, arr[i] - k);
        int curr_max = max(arr[n - 1] - k, arr[i - 1] + k);
        if (curr_max < curr_min) continue;      // as max till now can't be smaller than min till now hence ignore that element.
        ans = min(ans, curr_max - curr_min);
    }
    return ans;
}

int main(){
    int arr[] = {1, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    // Function call
    int result = getMinDiff(arr, n, k);

    // Output the result
    cout << "The minimum difference is: " << result << endl;

    return 0;
}

