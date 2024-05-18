#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        queue<int> q;
        bool visited[V] = {false};
        q.push(0);
        vector<int> traverse;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (!visited[node])
            {
                visited[node] = true;
                traverse.push_back(node);
            }
            for (int it : adj[node])
            {
                if (!visited[it])
                {

                    q.push(it);
                }
            }
        }
        return traverse;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        bool visited[V] = {false};
        stack<int> s;
        s.push(0);
        vector<int> t;
        while (!s.empty())
        {
            int n = s.top();
            s.pop();
            if (!visited[n])
            {
                visited[n] = true;
                t.push_back(n);
            }
            for (auto it : adj[n])
            {
                if (!visited[it])
                {
                    s.push(it);
                }
            }
        }
        return t;
    }
};
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}