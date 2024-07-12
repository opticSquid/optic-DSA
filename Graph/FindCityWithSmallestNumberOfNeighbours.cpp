#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    /**
     * convert the list of edges to adjustency matrix
     */
    void convertToadjMatrix(int n, vector<vector<int>> &edges, vector<vector<int>> &adjMatrix)
    {
        for (vector<int> e : edges)
        {
            // the path is birectional (given in question)
            adjMatrix[e[0]][e[1]] = e[2];
            adjMatrix[e[1]][e[0]] = e[2];
        }
        for (int i = 0; i < n; i++)
        {
            adjMatrix[i][i] = 0;
        }
    }

    /** find shortest distance between all the cities
     * no new Matrix will be created just adjMatrix will be manipulated
     * so, willl not return anything
     */
    void floydWarshall(int n, vector<vector<int>> &adjMatrix)
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    // if any one of the node is unreachable in the route
                    if (adjMatrix[i][k] == INT_MAX || adjMatrix[k][j] == INT_MAX)
                    {
                        continue;
                    }
                    // compare the previous computed distance with current computed distance
                    // and keep the minumum distance of both
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
    }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        // setting the dimensions of adjMatrix
        vector<vector<int>> adjMatrix(n, vector<int>(n, INT_MAX));
        // convert edgelist to adjMatrix
        convertToadjMatrix(n, edges, adjMatrix);
        // compute the shortest distance node to node
        floydWarshall(n, adjMatrix);
        int countMinNeigh = n;
        int node = -1;
        for (int i = 0; i < n; i++)
        {
            int currCount = 0;
            for (int j = 0; j < n; j++)
            {
                if (adjMatrix[i][j] <= distanceThreshold)
                {
                    currCount++;
                }
            }
            if (currCount <= countMinNeigh)
            {
                countMinNeigh = currCount;
                node = i;
            }
        }
        return node;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(e, vector<int>(3));
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    int thres;
    cin >> thres;
    Solution obj;
    cout << obj.findTheCity(n, edges, thres) << endl;
    return 0;
}