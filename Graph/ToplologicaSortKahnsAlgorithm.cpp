#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void calculate_indegree(vector<int> graph[], int len, unordered_map<int, int> &indegree)
    {
        for (int i = 0; i < len; i++)
        {
            // key is not present and encountering the key for first time
            if (indegree.find(i) == indegree.end())
            {
                indegree.insert({i, 0});
            }
            else
            {
                // increase the indegree by 1
                indegree[i]++;
            }
        }
    }
    /**
     * This algorithm uses a modified version of BFS
     * as suggested in Kahn's algorithm.
     */
    void kahns_algorithm_bfs(vector<int> graph[], int len, unordered_map<int, int> &indegree, stack<int> &result)
    {
        queue<int> q;
        // adding the nodes with indegree 0 to the q at first
        for (int i = 0; i < len; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            result.push(node);
            for (int child_node : graph[node])
            {
                // every time same node is encountered, decrese its indegree by 1
                indegree[child_node]--;
                // when the indegree becomes 0, push it to queue
                if (indegree[child_node] == 0)
                {
                    q.push(child_node);
                }
            }
        }
    }

public:
    stack<int> topologicalSort(vector<int> graph[], int len)
    {
        // we are using map in place of a simple array because what if the nodes are not continous in nature
        // there can be some nodes missing in that case array will still occupy that space
        // but in map we can skip that non existent node.
        // this is inspired by sparse matrix form of graph representation
        unordered_map<int, int> indegree;
        calculate_indegree(graph, len, indegree);
        stack<int> result;
        kahns_algorithm_bfs(graph, len, indegree, result);
        return result;
    }
};
int main()
{
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int v = 6;
    Solution obj;
    stack<int> res = obj.topologicalSort(adj, v);
    while (!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
    }
    return 0;
}