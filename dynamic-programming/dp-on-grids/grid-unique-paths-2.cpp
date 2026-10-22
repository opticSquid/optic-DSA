#include <bits/stdc++.h>
#include <cassert>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.empty())
        {
            return 0;
        }
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> prevRow(n, 0), curRow(n);
        int top, left;
        for (int i = 0; i < m; i++)
        {
            fill(curRow.begin(), curRow.end(), 0);
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    if (i == 0 && j == 0)
                    {
                        curRow[0] = 1;
                        continue;
                    }
                    top = i - 1 >= 0 ? prevRow[j] : 0;
                    left = j - 1 >= 0 ? curRow[j - 1] : 0;
                    curRow[j] = top + left;
                }
            }
            swap(prevRow, curRow);
        }
        return prevRow[n - 1];
    }
};
int main()
{
    vector<vector<int>> grid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution obj;
    assert(obj.uniquePathsWithObstacles(grid) == 2);
    return 0;
}