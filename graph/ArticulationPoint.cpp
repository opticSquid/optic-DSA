#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int timer = 1;
    void dfs(int node, int parent, vector<bool> &vis, int tin[], int low[], vector<bool> &marked, vector<int> adj[])
    {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, vis, tin, low, marked, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1)
                    marked[node] = true;
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1)
            marked[node] = true;
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        int tin[V];
        int low[V];
        vector<bool> marked(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, tin, low, marked, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (marked[i])
                ans.push_back(i);
        }
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};
int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 4}, {2, 4}, {2, 3}, {3, 4}};

    vector<int> adj[n];
    for (auto it : edges)
    {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    vector<int> nodes = obj.articulationPoints(n, adj);
    for (auto node : nodes)
    {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}