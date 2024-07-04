#include <iostream>
#include <map>

using namespace std;

#define M 100 // Adjust as needed
#define N 100 // Adjust as needed

void common_ele(int mat[M][N], int n, int m) {
    map<int, int> mp;

    for (int j = 0; j < m; j++) {
        mp[mat[0][j]] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[mat[i][j]] == i) {
                mp[mat[i][j]] = i + 1;
            }

            if (i == n - 1 && mp[mat[i][j]] == n) cout << mat[i][j] << " ";
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    int mat[M][N];
    cout << "Enter the matrix elements row-wise:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }

    cout << "Common elements in all rows are: ";
    common_ele(mat, n, m);
    cout << endl;

    return 0;
}
