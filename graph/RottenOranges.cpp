#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &);
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    // keeps the track of rotten oranges by {{row, col}, time} where time is the time they will rot.
    queue<pair<pair<int, int>, int>> q;
    // keeps the record of all the rotten oranges
    // basically a visited array
    int vis[n][m];
    // keep the count of fresh oranges
    int cntFresh = 0;
    // if found a rotten orange
    //      push to q with time 0; mark it as rotten in vis array
    // or else
    //      mark as 0 in vis array
    // if found a fresh orange
    //      increase the count of fresh oranges
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else
            {
                vis[i][j] = 0;
            }
            if (grid[i][j] == 1)
            {
                cntFresh++;
            }
        }
    }
    // minimum time it took to rot all oranges
    int tm = 0;
    // deltas of coordinates of all the squares in all directions given a square
    // ex: if square is {1,1} then
    // sq[0]+drow[0], sq[0]+dcol[0] will give square at the top i.e., {0,1}
    // sq[0]+drow[1], sq[0]+dcol[1] will give square at the right i.e., {1,2}
    // sq[0]+drow[2], sq[0]+dcol[2] will give square at the bottom i.e., {2,1}
    // sq[0]+drow[3], sq[0]+dcol[3] will give square at the left i.e., {1,0}
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    // count of visited fresh oranges
    int cnt = 0;
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        // we need the time it took for all the oranges to rot so,
        tm = max(tm, t);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            // this is an innovative way to check for boundaries in a single if
            // paired with a check to see if the orange is already rotten
            // and visit only the fresh oranges on the grid not the initially rotten ones nor the vaccant spaces
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
                cnt++;
            }
        }
    }
    // if the count of visited fresh oranges; now count of oranges that has been rotten (not the initial rotten ones)
    // does not match with the initial count of frsh oranges
    // it means some of the oranges were unreachable by the rotten oranges
    // and they now still remain fresh.
    if (cntFresh != cnt)
    {
        return -1;
    }
    // return the time it took for all the oranges to rot
    return tm;
}
int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 1}, {0, 1, 2}};
    cout << "original" << endl;
    print(grid);
    cout << "time: " << orangesRotting(grid) << endl;
    // cout << orangesRotting(grid) << endl;
    return 0;
}
void print(vector<vector<int>> &grid)
{
    cout << "printing..." << endl;
    for (vector<int> rows : grid)
    {
        for (int orange : rows)
        {
            cout << orange << " ";
        }
        cout << endl;
    }
}