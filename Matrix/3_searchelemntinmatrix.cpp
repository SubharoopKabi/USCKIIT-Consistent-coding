#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m * n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int e = matrix[mid / n][mid % n];
        if (target < e) {
            end = mid - 1;
        } else if (target > e) {
            start = mid + 1;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    bool found = searchMatrix(matrix, target);
    cout << (found ? "found" : "not found ") << endl;
    return 0;
}


