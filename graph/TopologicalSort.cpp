#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int node, map<int, vector<int>> &graph, bool visited[], stack<int> &collector)
    {
        visited[node] = true;
        vector<int> childNodes = graph[node];
        for (int c : childNodes)
        {
            if (!visited[c])
            {
                dfs(c, graph, visited, collector);
            }
        }
        collector.push(node);
    }

public:
    stack<int> topologicalSort(map<int, vector<int>> &graph)
    {
        stack<int> sortedNodes;
        // 0 - default not visited
        // 1 - visited
        // bitset<1> visited[len];
        bool visited[graph.size()];
        memset(visited, false, graph.size() * sizeof(bool));
        for (int i = 0; i < graph.size(); i++)
        {
            // if not visited
            // if(visited[i].count()==0)
            if (!visited[i])
            {
                dfs(i, graph, visited, sortedNodes);
            }
        }
        return sortedNodes;
    }
};
int main()
{
    // sparse matrix form
    // nodes need not to be continous some can be missed.
    map<int, vector<int>> graph = {{0, {}},
                                   {1, {}},
                                   {2, {3}},
                                   {3, {1}},
                                   {4, {0, 1}},
                                   {5, {0, 2}}};
    Solution obj;
    stack<int> result = obj.topologicalSort(graph);
    while (!result.empty())
    {
        cout << result.top() << " ";
        result.pop();
    }
    return 0;
}