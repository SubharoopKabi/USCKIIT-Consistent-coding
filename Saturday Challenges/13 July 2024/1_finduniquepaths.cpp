#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1) return 0;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = 1;

    for (int i = 1; i < n; i++) {
        dp[i][0] = (obstacleGrid[i][0] == 1) ? 0 : dp[i-1][0];
    }

    for (int j = 1; j < m; j++) {
        dp[0][j] = (obstacleGrid[0][j] == 1) ? 0 : dp[0][j-1];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return dp[n-1][m-1];
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << "Number of unique paths: " << uniquePathsWithObstacles(grid) << endl;
    
    return 0;
}
