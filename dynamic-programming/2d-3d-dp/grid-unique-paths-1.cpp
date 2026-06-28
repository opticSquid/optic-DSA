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
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(m - 1, n - 1, dp);
    }
};
int main()
{
    Solution obj;
    assert(obj.uniquePaths(3, 2) == 3);
    assert(obj.uniquePaths(2, 4) == 4);
    return 0;
}