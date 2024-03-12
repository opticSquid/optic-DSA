#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> eventualSafeStates(int V, vector<int> adj[])
    {
        vector<int> adjRev[V];
        int inDegree[V] = {0};
        // reverse graph and calculate indegree
        for (int i = 0; i < V; i++)
        {
            for (int it : adj[i])
            {
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> safeNodes;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (int it : adjRev[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
int main()
{
    vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, {8}, {9}};
    int V = 12;
    Solution obj;
    vector<int> res = obj.eventualSafeStates(V, adj);
    for (int node : res)
    {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}