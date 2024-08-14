/**
 * Find shortest distance from source to each node in an undirected graph
 * in which all edges have unit weights
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestDistance(int n, int m, int source, pair<int, int> edgeList[])
    {
        // convert edgeList to adjList
        vector<int> adjList[n];
        for (int i = 0; i < m; i++)
        {
            adjList[edgeList[i].first].push_back(edgeList[i].second);
            adjList[edgeList[i].second].push_back(edgeList[i].first);
        }
        vector<int> distArray(n, 1e9);
        distArray[source] = 0;
        queue<int> q;
        q.push(source);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int i : adjList[node])
            {
                if (1 + distArray[node] < distArray[i])
                {
                    distArray[i] = 1 + distArray[node];
                    q.push(i);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (distArray[i] == 1e9)
            {
                distArray[i] = -1;
            }
        }
        return distArray;
    }
};
int main()
{
    int n, m, src;
    cin >> n >> m;
    pair<int, int> edges[m];
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }
    cin >> src;
    Solution obj;
    for (int i : obj.shortestDistance(n, m, src, edges))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}