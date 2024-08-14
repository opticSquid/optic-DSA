#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
private:
    bool isValid(int adjR, int adjC, int n, int m)
    {
        return adjR >= 0 && adjR < n && adjC >= 0 && adjC < m;
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        DisjointSet ds(n * m);
        int visited[n][m];
        memset(visited, 0, sizeof visited);
        int counter = 0;
        vector<int> ans;
        for (auto op : operators)
        {
            int row = op[0], col = op[1];
            if (visited[row][col])
            {
                ans.push_back(counter);
                continue;
            }
            visited[row][col] = 1;
            counter++;
            int dr[] = {+1, 0, -1, 0};
            int dc[] = {0, +1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int adjR = row + dr[i];
                int adjC = col + dc[i];
                if (isValid(adjR, adjC, n, m) && visited[adjR][adjC])
                {
                    int nodeNo = (row * m) + col;
                    int adjNodeNo = (adjR * m) + adjC;
                    if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo))
                    {
                        counter--;
                        ds.unionBySize(adjNodeNo, nodeNo);
                    }
                }
            }
            ans.push_back(counter);
        }
        return ans;
    }
};
int main()
{
    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1}, {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};

    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, operators);
    for (auto res : ans)
    {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}