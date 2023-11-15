#include <bits/stdc++.h>
using namespace std;
void convertToAdjustency(vector<vector<int>> &, int, int, vector<int>[]);
void print(int, vector<vector<int>>);
void print(vector<vector<int>>);
void print(int, vector<int>[]);
void dfs(int node, int visited[], vector<int> adjList[], vector<int> &connected_component)
{
    if (visited[node])
    {
        return;
    }
    else
    {
        visited[node] = 1;
        connected_component.push_back(node);
        for (int it : adjList[node])
        {
            dfs(it, visited, adjList, connected_component);
        }
    }
}
vector<vector<int>> dfsWrapper(int v, int e, vector<vector<int>> &edges)
{
    // Convert edgesVector to adjustencyList
    vector<int> adjList[v];
    convertToAdjustency(edges, e, v, adjList);
    print(v, adjList);
    int visited[v];
    memset(visited, 0, v * sizeof(int));
    vector<vector<int>> result;
    // doing dfs for every disconnected component
    // normally one dfs is enough for traversing all the connected components
    // it has disconnected components it will not traverse these nodes normally
    // so after one pass of dfs I'm checking in the array which node is remaining from the begining
    // then doing a dfs pass on that node
    // In this way all the nodes will be traversed
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            vector<int> connected_component;
            dfs(i, visited, adjList, connected_component);
            result.push_back(connected_component);
        }
    }
    // adds the number of disconnected components in the front
    result.insert(result.begin(), {(int)result.size()});
    return result;
}
int main()
{
    // Taking Input
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        // adding 1 row at a time with each loop itertion and in every row adding v1, v2
        edges.push_back({v1, v2});
    }
    print(e, edges);
    vector<vector<int>> res = dfsWrapper(v, e, edges);
    print(res);
    return 0;
}
void convertToAdjustency(vector<vector<int>> &edges, int e, int v, vector<int> adjList[])
{
    for (int i = 0; i < e; i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
}
void print(int e, vector<vector<int>> graphArray)
{
    cout << "printing graph array" << endl;
    for (int i = 0; i < e; i++)
    {
        cout << i << ": " << graphArray[i][0] << " " << graphArray[i][1] << endl;
    }
}
void print(vector<vector<int>> list)
{
    cout << "printing DFS traversal" << endl;
    for (auto it : list)
    {
        for (int n : it)
        {
            cout << n << " ";
        }
        cout << endl;
    }
}
void print(int v, vector<int> list[])
{
    cout << "printing adjustency list" << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << ": ";
        for (vector<int>::iterator it = list[i].begin(); it != list[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}