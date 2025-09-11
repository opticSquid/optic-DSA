#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<int>> edgeList_2_adj(int V, vector<vector<int>> edges)
    {
        vector<vector<int>> adjList(V);
        for (vector<int> edge : edges)
        {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }
        return adjList;
    }

    set<int> detect_cycle_bfs(int src, bool visited[], vector<vector<int>> &adj)
    {
        stack<pair<int, int>> s;
        s.push({src, -1});
        set<int> res;
        while (!s.empty())
        {
            int node = s.top().first;
            int parentNode = s.top().second;
            s.pop();
            visited[node] = true;
            for (int adjNode : adj[node])
            {
                if (parentNode != -1)
                {
                    if (adjNode != parentNode)
                    {
                        if (visited[adjNode])
                        {
                            res.insert(node + 1);
                            res.insert(adjNode + 1);
                        }
                        else
                        {
                            s.push({adjNode, node});
                        }
                    }
                }
                else
                {
                    s.push({adjNode, node});
                }
            }
        }
        return res;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int V = edges.size();
        bool visited[V];
        memset(visited, false, V * sizeof(bool));
        set<int> redundant;
        vector<vector<int>> adjList = edgeList_2_adj(V, edges);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                redundant = detect_cycle_bfs(i, visited, adjList);
            }
        }
        for (int i = V - 1; i >= 0; i--)
        {
            if (redundant.find(edges[i][0]) != redundant.end() && redundant.find(edges[i][1]) != redundant.end())
            {
                return edges[i];
            }
        }
        return {};
    }
};

vector<vector<int>> stringToVectorOfVectors(const string &);
int main()
{
    string input;
    cin >> input;
    vector<vector<int>> edges = stringToVectorOfVectors(input);
    Solution obj;
    vector<int> res = obj.findRedundantConnection(edges);
    cout << res[0] << ", " << res[1] << endl;
    return 0;
}
vector<vector<int>> stringToVectorOfVectors(const string &str)
{
    vector<vector<int>> result;
    stringstream ss(str);
    char delimiter;

    if (ss >> delimiter && delimiter != '[')
    {
        throw invalid_argument("Invalid format: Outer opening bracket missing.");
    }

    while (ss.peek() != ']' && ss.good())
    {
        vector<int> innerVector;
        int num;

        if (ss >> delimiter && delimiter != '[')
        {
            throw invalid_argument("Invalid format: Inner opening bracket missing.");
        }

        while (ss >> num)
        {
            innerVector.push_back(num);
            if (ss >> delimiter && delimiter == ']')
            {
                break;
            }
            else if (delimiter != ',')
            {
                throw invalid_argument("Invalid format: Expected ',' or ']'.");
            }
        }
        result.push_back(innerVector);

        if (ss.peek() == ',')
        {
            ss >> delimiter;
        }
    }

    if (ss >> delimiter && delimiter != ']')
    {
        throw invalid_argument("Invalid format: Outer closing bracket missing.");
    }

    if (ss.peek() != EOF)
    {
        throw invalid_argument("Invalid format: Trailing characters found.");
    }

    return result;
}