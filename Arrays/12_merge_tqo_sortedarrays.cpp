#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;

    while (i <= k and j < m) {
        if (arr1[i] < arr2[j])
            i++;
        else {
            swap(arr2[j++], arr1[k--]);
        }
    }
   
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main() {
    
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10, 12, 14};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    
    merge(arr1, arr2, n, m);

    
    cout << "Array 1 after merging: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Array 2 after merging: ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}