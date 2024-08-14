#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[])
    {
        vis[node] = 1;
        pathVis[node] = 1;

        // traverse for adjacent nodes
        for (auto it : adj[node])
        {
            // when the node is not visited
            if (!vis[it])
            {
                if (dfsCheck(it, adj, vis, pathVis) == true)
                    return true;
            }

            // if the node has been previously visited -
            // may be on same path may be on different path

            // and it is going to be visited on the same path again
            else if (pathVis[it])
            {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        int vis[V];
        memset(vis, 0, V * sizeof(int));
        int pathVis[V];
        memset(pathVis, 0, V * sizeof(int));
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfsCheck(i, adj, vis, pathVis) == true)
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    vector<int> adj[11] = {{},
                           {2},
                           {3},
                           {4, 7},
                           {5},
                           {6},
                           {},
                           {5},
                           {2, 9},
                           {10},
                           {8}};
    int V = 11;
    Solution obj;
    bool ans = obj.isCyclic(V, adj);

    if (ans)
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}