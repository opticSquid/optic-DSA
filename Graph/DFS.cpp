#include <bits/stdc++.h>
using namespace std;
void addEdge(set<int> adjList[], int u, int v);
void print(vector<int> list);
void print(int max_v, set<int> list[]);
void dfsTraversalRecursive(int visited[], int node, set<int> adjList[], vector<int> &dfs)
{
    if (visited[node])
    {
        return;
    }
    else
    {
        visited[node] = 1;
        dfs.push_back(node);
        for (int it : adjList[node])
        {
            dfsTraversalRecursive(visited, it, adjList, dfs);
        }
    }
}
void dfsTraversalStack(int firstNode, int visited[], vector<int> &dfs, set<int> adjList[])
{
    visited[firstNode] = 1;
    stack<int> s;
    s.push(firstNode);
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        dfs.push_back(node);
        for (int it : adjList[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                s.push(it);
            }
        }
    }
}
vector<int> dfsTraversalWrapper(int n, set<int> adjList[])
{
    int visited[n];
    memset(visited, 0, n * sizeof(int));
    vector<int> dfs;
    // dfsTraversalRecursive(visited, 0, adjList, dfs);
    dfsTraversalStack(0, visited, dfs, adjList);
    return dfs;
}
int main()
{
    int number_of_node = 10;
    set<int> adjList[number_of_node];
    // ! fully connected
    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 5);
    addEdge(adjList, 1, 6);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 2, 5);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 4, 5);
    addEdge(adjList, 4, 9);
    addEdge(adjList, 5, 6);
    addEdge(adjList, 5, 8);
    addEdge(adjList, 6, 7);
    addEdge(adjList, 7, 8);
    addEdge(adjList, 8, 9);
    print(number_of_node, adjList);
    vector<int> dfs = dfsTraversalWrapper(number_of_node, adjList);
    print(dfs);
    return 0;
}
void addEdge(set<int> adjList[], int u, int v)
{
    adjList[u].insert(v);
    adjList[v].insert(u);
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
void print(int max_v, set<int> list[])
{
    cout << "printing adjustency list" << endl;
    for (int i = 0; i < max_v; i++)
    {
        cout << i << ": ";
        for (set<int>::iterator it = list[i].begin(); it != list[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}