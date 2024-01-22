#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(pair<int, int> node, int **arr, pair<int, int> boundary, int *delRow, int *delCol)
    {
        arr[node.first][node.second] = -1;
        for (int i = 0; i < 8; i++)
        {
            int nrow = node.first + delRow[i];
            int ncol = node.second + delCol[i];
            if (nrow >= 0 && nrow < boundary.first && ncol >= 0 && ncol < boundary.second && arr[nrow][ncol] != -1 && arr[nrow][ncol] == 1)
            {
                dfs({nrow, ncol}, arr, boundary, delRow, delCol);
            }
        }
    }

public:
    int distinctIslands(int **arr, int n, int m)
    {
        // top, top-right, right, bottom-right, bottom, bottom-left, left, top-left
        int delRow[] = {-1, -1, 0, +1, +1, +1, 0, -1};
        int delCol[] = {0, +1, +1, +1, 0, -1, -1, -1};
        int countIsland = 0;
        for (int i = 0; i < max(m, n); i++)
        {
            // cell content -1 = visited
            if (i < m)
            {
                // first row
                if (arr[0][i] != -1 && arr[0][i] == 1)
                {
                    dfs({0, i}, arr, {n, m}, delRow, delCol);
                    countIsland++;
                }
                // last row
                if (arr[n - 1][i] != -1 && arr[n - 1][i] == 1)
                {
                    dfs({n - 1, i}, arr, {n, m}, delRow, delCol);
                    countIsland++;
                }
            }
            if (i < n)
            {
                // first col
                if (arr[i][0] != -1 && arr[i][0] == 1)
                {
                    dfs({i, 0}, arr, {n, m}, delRow, delCol);
                    countIsland++;
                }
                // last col
                if (arr[i][m - 1] != -1 && arr[i][m - 1] == 1)
                {
                    dfs({i, m - 1}, arr, {n, m}, delRow, delCol);
                    countIsland++;
                }
            }
        }
        return countIsland;
    }
};
int main()
{
    int grid[5][4] = {{0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {0, 0, 1, 0},
                      {0, 0, 0, 0},
                      {1, 1, 0, 1}};
    // Convert the 2D array to a pointer to an array of pointers
    int *arr[5];
    for (int i = 0; i < 5; ++i)
    {
        arr[i] = grid[i];
    }
    Solution obj;
    cout << obj.distinctIslands(arr, 5, 4) << endl;
}