#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool dfs(int startingNode, vector<int> graph[], int visited[])
    {
        stack<pair<int, int>> s;
        s.push({startingNode, -1});
        while (!s.empty())
        {
            int node = s.top().first;
            int parent = s.top().second;
            visited[node] = 1;
            s.pop();
            for (int neighbour : graph[node])
            {

                if (parent != -1)
                {
                    if (neighbour != parent)
                    {
                        if (visited[neighbour])
                        {
                            return true;
                        }
                        else
                        {
                            s.push({neighbour, node});
                        }
                    }
                }
                else
                {
                    s.push({neighbour, node});
                }
            }
        }
        return false;
    }

public:
    bool detectCycle(int V, vector<int> adj[])
    {
        int visited[V];
        memset(visited, 0, V * sizeof(int));
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    vector<int> edges[] = {{0, 1},
                           {0, 2},
                           {1, 3, 4},
                           {2, 5},
                           {2, 5, 6},
                           {3, 4},
                           {4}};
    // vector<int> edges[] = {{12, 8},
    //                        {1, 3},
    //                        {1, 11},
    //                        {2, 9},
    //                        {5, 11}};
    int v = 7;
    Solution obj;
    cout << "result: " << obj.detectCycle(v, edges) << endl;
    return 0;
}