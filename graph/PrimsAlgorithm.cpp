#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        // {wt, node}
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty())
        {
            pair<int, int> it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            if (vis[node] == 1)
                continue;
            vis[node] = 1;
            sum += wt;
            for (vector<int> i : adj[node])
            {
                int adjNode = i[0];
                int edgWt = i[1];
                if (!vis[adjNode])
                {
                    pq.push({edgWt, adjNode});
                }
            }
        }
        return sum;
    }
};
int main()
{
    Solution obj;
    return 0;
}