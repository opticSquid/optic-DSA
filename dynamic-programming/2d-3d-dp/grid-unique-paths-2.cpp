#include <bits/stdc++.h>
#include <cassert>
using namespace std;
class Solution
{
private:
    int traverse(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (grid[i][j] == 1)
        {
            return dp[i][j] = 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (i == 0 && j == 0)
        {
            return dp[i][j] = 1;
        }
        int top = traverse(i - 1, j, grid, dp);
        int left = traverse(i, j - 1, grid, dp);
        return dp[i][j] = top + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.empty())
        {
            return 0;
        }
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return traverse(m - 1, n - 1, obstacleGrid, dp);
    }
};
int main()
{
    vector<vector<int>> grid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution obj;
    assert(obj.uniquePathsWithObstacles(grid) == 2);
    return 0;
}