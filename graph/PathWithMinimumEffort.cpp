#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size(), m = heights[0].size();
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};
        pair<int, int> origin = {0, 0};
        pair<int, int> destination = {n - 1, m - 1};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        // effort of origin is 0
        effort[0][0] = 0;
        // adding origin with effort 0 in pq
        pq.push({effort[0][0], origin});
        while (!pq.empty())
        {
            pair<int, int> node = pq.top().second;
            int currEff = pq.top().first;
            pq.pop();
            // if destination reached
            // return current effort
            if (node == destination)
            {
                return currEff;
            }
            for (int i = 0; i < 4; i++)
            {
                int nr = node.first + dr[i], nc = node.second + dc[i];
                // bounding box
                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    // Effort can be calculated as the max value of differences
                    // between the heights of the node and its adjacent nodes.
                    int nMinEffort = max(abs(heights[node.first][node.second] - heights[nr][nc]), currEff);
                    // If the calculated effort is less than the prev value
                    // we update as we need the min effort.
                    if (nMinEffort < effort[nr][nc])
                    {
                        effort[nr][nc] = nMinEffort;
                        pq.push({nMinEffort, {nr, nc}});
                    }
                }
            }
        }
        // if unreachable
        return 0;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.minimumEffortPath(grid) << endl;
    return 0;
}