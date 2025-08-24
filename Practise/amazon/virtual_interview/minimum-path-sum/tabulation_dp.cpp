#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int travel(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &paths)
    {
        if (i == 0 && j == 0)
        {
            return grid[i][j];
        }
        else if (i < 0 || j < 0)
        {
            return 1e5;
        }
        else if (paths[i][j] != -1)
        {
            return paths[i][j];
        }
        else
        {
            int u = travel(i - 1, j, grid, paths);
            int l = travel(i, j - 1, grid, paths);
            return grid[i][j] + min(u, l);
        }
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int paths[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    paths[i][j] = grid[i][j];
                }
                else
                {
                    int u = 1e5, l = 1e5;
                    if (i > 0)
                        u = paths[i - 1][j];
                    if (j > 0)
                        l = paths[i][j - 1];
                    paths[i][j] = grid[i][j] + min(u, l);
                }
            }
        }
        return paths[m - 1][n - 1];
    }
};
int main()
{
    Solution obj;
    return 0;
}