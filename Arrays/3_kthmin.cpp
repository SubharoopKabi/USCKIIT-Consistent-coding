// Find Kth minimum element

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k)
{
    sort(arr, arr + n);
    return arr[k - 1];
}


int main()
{
    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 2;

    cout << "K'th minimum element is "<< kthSmallest(arr, n, K);
         
    return 0;
}