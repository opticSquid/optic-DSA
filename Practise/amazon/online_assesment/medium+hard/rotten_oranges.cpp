#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size(), mins = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                    tot++;
                if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }
        vector<int> dx = {-1, 0, +1, 0};
        vector<int> dy = {0, +1, 0, -1};
        while (!rotten.empty())
        {
            int k = rotten.size();
            cnt += k;
            while (k--)
            {
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        rotten.push({nx, ny});
                    }
                }
            }
            if (!rotten.empty())
                mins++;
        }
        return tot == cnt ? mins : -1;
    }
};
int main()
{
    Solution obj;
    return 0;
}