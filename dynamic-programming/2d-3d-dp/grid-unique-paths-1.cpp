#include <bits/stdc++.h>
#include <cassert>
using namespace std;
class Solution
{
private:
    int countPaths(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            return 1;
        }
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int up = countPaths(i - 1, j, dp);
        int left = countPaths(i, j - 1, dp);
        return dp[i][j] = up + left;
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int left, up;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                up = i - 1 >= 0 ? dp[i - 1][j] : 0;
                left = j - 1 >= 0 ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main()
{
    Solution obj;
    assert(obj.uniquePaths(3, 2) == 3);
    assert(obj.uniquePaths(2, 4) == 4);
    return 0;
}