#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int m, n;
    int traverse(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        // If out of boundary
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return RES_MAX;
        }
        if (dp[i][j] != RES_MAX)
        {
            return dp[i][j];
        }
        if (i == 0)
        {
            return dp[i][j] = matrix[i][j];
        }
        vector<int> mvs(3);
        // top-left
        mvs[0] = matrix[i][j] + traverse(i - 1, j - 1, matrix, dp);
        // top
        mvs[1] = matrix[i][j] + traverse(i - 1, j, matrix, dp);
        // top-right
        mvs[2] = matrix[i][j] + traverse(i - 1, j + 1, matrix, dp);
        return dp[i][j] = *min_element(mvs.begin(), mvs.end());
    }

public:
    static inline constexpr int RES_MAX = 2047483647; // little less than INT_MAX to stop overflow
    Solution() : m(0), n(0)
    {
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
        {
            return 0;
        }
        this->m = matrix.size();
        this->n = matrix[0].size();
        vector<vector<int>> dp(m, vector(n, RES_MAX));
        int min_sum = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
        {
            min_sum = min(min_sum, traverse(m - 1, i, matrix, dp));
        }
        return min_sum;
    }
};
int main()
{
    return 0;
}