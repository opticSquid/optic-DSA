#include <bits/stdc++.h>
using namespace std;
void print(vector<int> list);
void print(int max_v, vector<int> list[]);
void bfsTraversal(int starting_node, vector<int> graph[], int visited[], vector<int> &result)
{
    queue<int> q;
    q.push(starting_node);
    while (!q.empty())
    {
        vector<int> bfs;
        int node = q.front();
        q.pop();
        result.push_back(node);
        for (int it : graph[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
}
vector<int> bfsTraversalWrapper(int max_k, vector<int> adjList[])
{
    int visited[max_k];
    // fills the array with zeros in an efficient way
    memset(visited, 0, max_k * sizeof(int));
    // visited[0] = 1;
    vector<int> bfs;
    for (int i = 0; i < max_k; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            bfsTraversal(i, adjList, visited, bfs);
        }
    }
    return bfs;
}
void addEdge(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int main()
{
    vector<int> adjList[6];
    // ! not connected at start
    // addEdge(adjList, 1, 2);
    // addEdge(adjList, 1, 3);
    // addEdge(adjList, 2, 3);
    // addEdge(adjList, 2, 4);
    // addEdge(adjList, 3, 4);
    // addEdge(adjList, 4, 5);
    // ! not connected at middle
    // addEdge(adjList, 0, 1);
    // addEdge(adjList, 1, 2);
    // addEdge(adjList, 1, 5);
    // addEdge(adjList, 2, 5);
    // addEdge(adjList, 5, 4);
    // ! not connected at end
    // addEdge(adjList, 0, 1);
    // addEdge(adjList, 1, 2);
    // addEdge(adjList, 2, 3);
    // addEdge(adjList, 2, 4);
    // addEdge(adjList, 3, 4);
    // ! fully connected
    // addEdge(adjList, 0, 1);
    // addEdge(adjList, 1, 2);
    // addEdge(adjList, 1, 5);
    // addEdge(adjList, 2, 3);
    // addEdge(adjList, 2, 5);
    // addEdge(adjList, 3, 4);
    // addEdge(adjList, 3, 5);
    // addEdge(adjList, 4, 5);
    // ! two seperate unconnected components with multiple nodes
    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 4, 5);
    print(6, adjList);
    vector<int> bfs = bfsTraversalWrapper(6, adjList);
    print(bfs);
    return 0;
}
void print(vector<int> list)
{
    cout << "printing BFS traversal" << endl;
    for (auto it : list)
    {
        cout << it << " ";
    }
    cout << endl;
}
void print(int max_v, vector<int> list[])
{
    cout << "printing adjustency list" << endl;
    for (int i = 0; i < max_v; i++)
    {
        cout << i << ": ";
        for (vector<int>::iterator it = list[i].begin(); it != list[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}