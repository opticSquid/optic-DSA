#include <bits/stdc++.h>
#include <cassert>
using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.empty())
        {
            return 0;
        }
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int top, left;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    if (i == 0 && j == 0)
                    {
                        dp[0][0] = 1;
                        continue;
                    }
                    top = i - 1 >= 0 ? dp[i - 1][j] : 0;
                    left = j - 1 >= 0 ? dp[i][j - 1] : 0;
                    dp[i][j] = top + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main()
{
    vector<vector<int>> grid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution obj;
    assert(obj.uniquePathsWithObstacles(grid) == 2);
    return 0;
}