#include <bits/stdc++.h>
using namespace std;
bool bfs(int src, int visited[], vector<int> adj[])
{
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parentNode = q.front().second;
        q.pop();
        for (int adjNode : adj[node])
        {
            if (!visited[adjNode])
            {
                visited[adjNode] = 1;
                q.push({adjNode, node});
            }
            else
            {
                if (parentNode != adjNode)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool detectCycle(int V, vector<int> edges[])
{
    int visited[V];
    memset(visited, 0, V * sizeof(int));
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            // visited[i] = 1;
            if (bfs(i, visited, edges))
                return true;
        }
    }
    return false;
}
int main()
{
    vector<int> edges[] = {{0, 1}, {1, 2}, {3, 4}};
    int v = 4;
    cout << "result: " << detectCycle(v, edges);
    return 0;
}