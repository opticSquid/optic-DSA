#include <bits/stdc++.h>
using namespace std;
class CountEnclaves
{
private:
    int delRow[4] = {-1, 0, +1, 0};
    int delCol[4] = {0, +1, 0, -1};
    void dfs(pair<int, int> node, vector<vector<int>> &grid, pair<int, int> boundary)
    {
        grid[node.first][node.second] = 2;
        for (int i = 0; i < 4; i++)
        {
            int nrow = delRow[i] + node.first;
            int ncol = delCol[i] + node.second;
            // if within the bounding box and is '1'
            if (nrow >= 0 && nrow < boundary.first && ncol >= 0 && ncol < boundary.second && grid[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                dfs({nrow, ncol}, grid, boundary);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        // traverse the boundary cells first searching for '1'
        for (int i = 0; i < max(grid.size(), grid[0].size()); i++)
        {
            if (i < n)
            {
                // first row
                if (grid[0][i] != 2 && grid[0][i] == 1)
                {
                    dfs({0, i}, grid, {m, n});
                }

                // last row
                if (grid[m - 1][i] != 2 && grid[m - 1][i] == 1)
                {
                    dfs({m - 1, i}, grid, {m, n});
                }
            }
            if (i < m)
            {
                // first col
                if (grid[i][0] != 2 && grid[i][0] == 1)
                {
                    dfs({i, 0}, grid, {m, n});
                }

                // last col
                if (grid[i][n - 1] != 2 && grid[i][n - 1] == 1)
                {
                    dfs({i, n - 1}, grid, {m, n});
                }
            }
        }
        // Till here all the '1' cells connected to boundary will be visited.
        // So, they won't be counted as enclaves.
        // Now for a little optimization I will only iterate through the interior of the grid
        // because '1' cells in boundary does not count as enclaves
        // To count enclaves, I want to check if the cell is still unvisited and contains '1'
        int counter = 0;
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j] != 2 && grid[i][j] == 1)
                {
                    counter++;
                }
            }
        }
        return counter;
    }
};
int main()
{
    vector<vector<int>> grid =
        {{0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
         {1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
         {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
         {0, 1, 1, 0, 0, 0, 1, 0, 1, 0},
         {0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
         {0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
         {0, 1, 1, 0, 0, 0, 1, 1, 1, 1},
         {0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
         {1, 0, 1, 0, 1, 1, 0, 0, 0, 0},
         {0, 0, 0, 0, 1, 1, 0, 0, 0, 1}};
    CountEnclaves obj;
    cout << obj.numEnclaves(grid) << endl;
}