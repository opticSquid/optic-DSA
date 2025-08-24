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
        vector<vector<int>> paths(m, vector<int>(n, -1));
        return travel(m - 1, n - 1, grid, paths);
    }
};
int main()
{
    Solution obj;
    return 0;
}