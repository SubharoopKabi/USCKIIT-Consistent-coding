#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int binaryMedian(vector<vector<int>>& matrix, int r, int c) {
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < r; i++) {
        mn = min(mn, matrix[i][0]);
        mx = max(mx, matrix[i][c - 1]);
    }

    int desired = (r * c + 1) / 2;
    while (mn < mx) {
        int mid = mn + (mx - mn) / 2;
        int place = 0;

        for (int i = 0; i < r; ++i) {
            place += upper_bound(matrix[i].begin(), matrix[i].begin() + c, mid) - matrix[i].begin();
        }

        if (place < desired) {
            mn = mid + 1;
        } else {
            mx = mid;
        }
    }
    return mn;
}

int main() {
    int r, c;
    cout << "Enter the number of rows in the matrix: ";
    cin >> r;
    cout << "Enter the number of columns in the matrix: ";
    cin >> c;

    vector<vector<int>> matrix(r, vector<int>(c));
    cout << "Enter the matrix elements row-wise:\n";
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> matrix[i][j];
        }
    }

    int median = binaryMedian(matrix, r, c);
    cout << "The median of the matrix is: " << median << endl;

    return 0;
}
