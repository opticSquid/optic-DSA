#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void topologicalSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st)
    {
        vis[node] = 1;
        for (pair<int, int> it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
            {
                topologicalSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];
        // converting edges to adjList
        // edges are in format [{u,v,wt},{u,v,wt}....]
        for (int i = 0; i < M; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        int visited[N] = {0};
        stack<int> st;
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                topologicalSort(i, adj, visited, st);
            }
        }
        vector<int> distance(N, 1e9);
        distance[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                // check if the current node distance from source + weight
                if (distance[node] + wt < distance[v])
                {
                    distance[v] = distance[node] + wt;
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            distance[i] = distance[i] == 1e9 ? -1 : distance[i];
        }
        return distance;
    }
};
int main()
{
    // n = number of vertices
    // m = number of edges between them
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> edges[i][j];
        }
    }
    Solution obj;
    vector<int> distance = obj.shortestPath(n, m, edges);
    int a = 0;
    for (int d : distance)
    {
        cout << a << " => " << d << endl;
        a++;
    }
    return 0;
}