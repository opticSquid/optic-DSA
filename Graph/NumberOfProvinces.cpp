#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &);
void print(int, vector<int>[]);
void bfs(int visited[], int startingNode, vector<int> adjList[])
{
    queue<int> q;
    q.push(startingNode);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int it : adjList[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return;
}
void dfs(int visited[], int startingNode, vector<int> adjList[])
{
    stack<int> s;
    s.push(startingNode);
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        for (int it : adjList[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                s.push(it);
            }
        }
    }
    return;
}
int findCircleNum(vector<vector<int>> &roads)
{
    // print(roads);
    int n = roads.size();
    vector<int> adjList[n];
    // convert adjustencyMatrix to adjustencyList
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || roads[i][j] == 0)
            {
                continue;
            }
            else
            {
                adjList[i].push_back(j);
            }
        }
    }
    // print(n, adjList);
    int counter = 0;
    // initiating dfs
    int visited[n];
    memset(visited, 0, n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            vector<int> component;
            bfs(visited, i, adjList);
            counter++;
        }
    }
    return counter;
}
int main()
{
    int n;
    cin >> n;
    // creating a nxn vector
    vector<vector<int>> graphMartix(n, vector(n, 0));
    // graphMartix[0][0] = 1;
    // graphMartix[0][1] = 1;
    // graphMartix[1][0] = 1;
    // graphMartix[1][1] = 1;
    // graphMartix[2][2] = 1;
    // graphMartix[0][0] = 1;
    // graphMartix[1][1] = 1;
    // graphMartix[2][2] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            graphMartix[i][j] = x;
        }
    }
    cout << findCircleNum(graphMartix) << endl;
}
void print(vector<vector<int>> &isConnected)
{
    cout << "Graph Matrix" << endl;
    for (vector<int> it : isConnected)
    {
        for (int i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void print(int n, vector<int> adjList[])
{
    cout << "Graph List" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int k : adjList[i])
        {
            cout << k << " ";
        }
        cout << endl;
    }
}
