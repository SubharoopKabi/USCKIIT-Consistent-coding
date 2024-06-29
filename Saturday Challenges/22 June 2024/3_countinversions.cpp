#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long ans = 0LL;
    for (int i = 0;i < N;i++) {
        for (int j = i + 1;j < N;j++) {
            if (arr[j] < arr[i]) ans++;
        }
    }
    return ans;
}

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    int inv_count = 0;

    i = left; 
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count += mid - i;
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}


int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
       
        mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}


int main()
{
    int arr[] = { 70, 50, 60, 10, 20, 30, 80, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[100];
    int ans = _mergeSort(arr, temp, 0, n - 1);
    cout << " Number of inversions are " << ans;
    return 0;
}