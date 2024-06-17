#include<bits/stdc++.h>
using namespace std;

void rotatebyone(int arr[], int n)
{
    int temp = arr[n - 1];

    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {1, 2, 4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    printArray(a, n);

    rotatebyone(a, n);

    cout << "New array: ";
    printArray(a, n);

    return 0;
}
