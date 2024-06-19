#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int searchinrotatedarray(int A[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low < high) {
        int mid = (low + high) / 2;
        if (A[mid] > A[high]) low = mid + 1;
        else high = mid;
    }
    int rot = low;
    low = 0;high = n - 1;
   
    while (low <= high) {
        int mid = (low + high) / 2;
        int realmid = (mid + rot) % n;
        if (A[realmid] == target)return realmid;
        if (A[realmid] < target)low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}


int main() {

    int A[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(A) / sizeof(A[0]);

    int target = 3;

    int result = searchinrotatedarray(A, n, target);

    if (result != -1) {
        cout << "Target " << target << " found at index " << result << ".\n";
    } else {
        cout << "Target " << target << " not found in the array.\n";
    }

    return 0;
}
