#include <iostream>
using namespace std;


int numTrees(int n) {
    // Base case for 0 nodes (one empty tree)
    if (n == 0) {
        return 1;
    }

    int arr[100];
    arr[0] = 1; 

    // Recurrence realtion for Catalan Numbers
    for (int i = 1; i <= n; ++i) {
        arr[i] = 0;
        for (int j = 0; j < i; ++j) {
            arr[i] += arr[j] * arr[i - 1 - j];
        }
    }

    return arr[n];
}


int main() {
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Number of unique BSTs with " << n << " nodes: " << numTrees(n) << endl;

    return 0;
}