#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        // top, top-right, right, bottom-right, bottom, bottom-left, left, top-left
        int del_row[] = {-1, -1, 0, +1, +1, +1, 0, -1};
        int del_col[] = {0, +1, +1, +1, 0, -1, -1, -1};
        // if source cell does not contain 0
        // traversing not possible
        if (grid[0][0] != 0)
        {
            return -1;
        }
        // its just a single cell grid
        if (n - 1 == 0)
        {
            return 1;
        }
        // distance array
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        // could have used priority queue
        // but priority queue implementation is consistently slower by 20ms or more
        queue<pair<int, pair<int, int>>> q;
        // pushing source to pq
        q.push({0, {0, 0}});
        // making source distance 0
        dist[0][0] = 1;
        while (!q.empty())
        {
            pair<int, int> node = q.front().second;
            int distance = q.front().first;
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int n_row = node.first + del_row[i];
                int n_col = node.second + del_col[i];
                int curr_dist = distance + 1;
                // boundary condition and content check
                // and if current calculated distance less than previous distance
                if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < n && grid[n_row][n_col] == 0 && curr_dist < dist[n_row][n_col])
                {
                    // update to new lesser distance
                    dist[n_row][n_col] = curr_dist;
                    // if destination reached
                    if (n_row == n - 1 && n_col == n - 1)
                    {
                        // return answer
                        return dist[n_row][n_col] + 1;
                    }
                    // add to queue
                    q.push({curr_dist, {n_row, n_col}});
                }
            }
        }
        return -1;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    Solution obj;
    cout << obj.shortestPathBinaryMatrix(g) << endl;
    return 0;
}