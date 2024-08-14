#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    vector<int> rank, size;

public:
    vector<int> parent;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
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
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int u_up = findUPar(u);
        int v_up = findUPar(v);
        if (u_up == v_up)
            return;
        else if (rank[u_up] < rank[v_up])
        {
            parent[u_up] = v_up;
        }
        else if (rank[v_up] < rank[u_up])
        {
            parent[v_up] = u_up;
        }
        else
        {
            parent[v_up] = u_up;
            rank[u_up]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int u_up = findUPar(u);
        int v_up = findUPar(v);
        if (u_up == v_up)
            return;
        else if (size[u_up] < size[v_up])
        {
            parent[u_up] = v_up;
            size[v_up] += size[u_up];
        }
        else
        {
            parent[v_up] = u_up;
            size[u_up] += size[v_up];
        }
    }
};
class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSet ds(n);
        int cntExtras = 0;
        for (auto it : connections)
        {
            // if they belong to same component
            if (ds.findUPar(it[0]) == ds.findUPar(it[1]))
            {
                cntExtras++;
            }
            // if they belong to different components
            else
            {
                ds.unionByRank(it[0], it[1]);
            }
        }

        int cntC = 0;
        for (int i = 0; i < n; i++)
        {
            // if ultimate parent node
            if (ds.parent[i] == i)
                cntC++;
        }
        return cntExtras >= cntC - 1 ? cntC - 1 : -1;
    }
};
int main()
{
    Solution obj;
    return 0;
}