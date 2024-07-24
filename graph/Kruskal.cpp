#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    vector<int> rank, parent, size;

public:
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

    int findUParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int u_up = findUParent(u);
        int v_up = findUParent(v);
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
        // if equal rank
        else
        {
            // make ultimate parent of u the ultimate parent of v;
            parent[v_up] = u_up;
            // increase the rank of ultimate parent of u
            rank[u_up]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int u_up = findUParent(u);
        int v_up = findUParent(v);
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
private:
    bool static comp(vector<int> a, vector<int> b)
    {
        if (a[0] != b[0])
            return a[0] < b[0];
        else if (a[1] != b[1])
            return a[1] < b[1];
        else
            return a[2] < b[2];
    }

public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    // adj will be in the form
    // 0 | {{1,2}, {4,3}}            int mstWt = 0;
    // 1 | {{3,0}}
    // 2 | {{4,6}, {5,1}, {2,6}}
    // ...
    // where {4,6} in the form {wt, v}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // every row in edges would be like {wt,u,v}
        vector<vector<int>> edges;
        for (int i = 0; i < V; i++)
        {
            for (vector<int> it : adj[i])
            {
                int wt = it[1];
                int v = it[0];
                int u = i;
                edges.push_back({wt, u, v});
            }
        }
        sort(edges.begin(), edges.end(), comp);
        DisjointSet ds(V);
        int mstWt = 0;
        for (vector<int> e : edges)
        {
            int wt = e[0];
            int u = e[1];
            int v = e[2];
            if (ds.findUParent(u) != ds.findUParent(v))
            {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWt;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj[n];
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    Solution obj;
    cout << obj.spanningTree(n, adj) << endl;
    return 0;
}