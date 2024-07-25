#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs1(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs1(it, vis, st, adj);
            }
        }
        st.push(node);
    }
    void dfs2(int node, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs2(it, vis, adj);
            }
        }
    }

public:
    int kosaraju(int n, vector<vector<int>> &adj)
    {
        vector<int> vis(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs1(i, vis, st, adj);
            }
        }

        vector<vector<int>> adjRev(n);
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                adjRev[it].push_back(i);
            }
        }

        int ssc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                dfs2(node, vis, adjRev);
                ssc++;
            }
        }
        return ssc;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}