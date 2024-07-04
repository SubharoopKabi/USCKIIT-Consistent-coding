#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
    int row = 0, col = m - 1, ans = -1;

    while (col >= 0 && row < n) {
        if (arr[row][col] == 1) {
            ans = row;
            col--;
        } else {
            row++;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    cout << "Enter the matrix elements row-wise:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    int result = rowWithMax1s(arr, n, m);
    if (result != -1) {
        cout << "The row with the maximum number of 1s is: " << result+1 << endl;
    } else {
        cout << "No 1s found in the matrix." << endl;
    }

    return 0;
}
