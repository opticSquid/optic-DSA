#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<int> delrow = {-1, 0, +1, 0};
    vector<int> delcol = {0, +1, 0, -1};
    void visit(vector<vector<char>> &grid, int cr, int cc, int rows, int cols)
    {
        stack<pair<int, int>> s;
        s.push({cr, cc});
        while (!s.empty())
        {
            pair<int, int> pos = s.top();
            s.pop();
            grid[pos.first][pos.second] = '2';
            for (int i = 0; i < 4; i++)
            {
                int nrow = pos.first + delrow[i];
                int ncol = pos.second + delcol[i];
                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && grid[nrow][ncol] == '1')
                {
                    s.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int islands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    visit(grid, i, j, m, n);
                    islands++;
                }
            }
        }
        return islands;
    }
};
int main()
{
    Solution obj;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    cout << obj.numIslands(grid) << endl;
    return 0;
}