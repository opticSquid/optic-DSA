#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int timer = 1;
    void dfs(int parent, int node, vector<int> adj[], bool vis[], int tin[], int low[], vector<vector<int>> &bridges)
    {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(node, it, adj, vis, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node])
                {
                    bridges.push_back({node, it});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto c : connections)
        {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        bool vis[n];
        memset(vis, false, sizeof vis);
        int tin[n], low[n];
        vector<vector<int>> bridges;
        dfs(-1, 0, adj, vis, tin, low, bridges);
        return bridges;
    }
};
int main()
{
    Solution obj;
    return 0;
}