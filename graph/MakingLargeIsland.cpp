#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    vector<int> parent;

public:
    vector<int> size;
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int up_u = findUPar(u);
        int up_v = findUPar(v);
        if (up_u == up_v)
            return;
        else if (size[up_u] > size[up_v])
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
        else
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
    }
};
class Solution
{
private:
    bool isValid(int newr, int newc, int n)
    {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};
        // step 1
        // creating disjointset of the existing components
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                    continue;
                for (int idx = 0; idx < 4; idx++)
                {
                    int nr = row + dr[idx];
                    int nc = col + dc[idx];
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1)
                    {
                        int nodeNo = row * n + col;
                        int adjNodeNo = nr * n + nc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        // step 2
        // changing every 0 to 1 and checking if the adjuscent nodes are 1
        // if nodes are 1 getting the ultimate parent of that component and storing in that components set;
        int mx = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;
                set<int> components;
                for (int idx = 0; idx < 4; idx++)
                {
                    int nr = row + dr[idx];
                    int nc = col + dc[idx];
                    if (isValid(nr, nc, n))
                    {
                        if (grid[nr][nc] == 1)
                        {
                            components.insert(ds.findUPar(nr * n + nc));
                        }
                    }
                }
                int sizeTotal = 0;
                for (int it : components)
                {
                    sizeTotal += ds.size[it];
                }
                // sizeTotal+1 because we will also consider the cell that we changed from 0 to 1
                mx = max(mx, sizeTotal + 1);
            }
        }
        // step 3 (safety check)
        // check after changing 0s to 1s
        for (int cellNo = 0; cellNo < n; cellNo++)
        {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        return mx;
    }
};
int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 0}};

    Solution obj;
    int ans = obj.largestIsland(grid);
    cout << "The largest group of connected 1s is of size: " << ans << endl;
    return 0;
}