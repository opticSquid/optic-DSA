#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    double bfs(const string start, const string end, unordered_map<string, vector<pair<string, double>>> &adjList)
    {
        if ((adjList.find(start) == adjList.end()) || (adjList.find(end) == adjList.end()))
        {
            return -1.00;
        }
        queue<pair<string, double>> q;
        unordered_set<string> vis;
        q.push({start, 1.00});
        while (!q.empty())
        {
            auto [node, w] = q.front();
            q.pop();
            if (node == end)
            {
                return w;
            }
            vis.insert(node);
            for (pair<string, double> neighbours : adjList[node])
            {
                if (vis.find(neighbours.first) == vis.end())
                {
                    q.push({neighbours.first, w * neighbours.second});
                }
            }
        }
        return -1.00;
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, vector<pair<string, double>>> adjList;
        int n = values.size();
        for (int i = 0; i < n; i++)
        {
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back({equations[i][0], (double)1.00 / values[i]});
        }
        vector<double> res;
        for (const auto &q : queries)
        {
            res.push_back(bfs(q[0], q[1], adjList));
        }
        return res;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<string>> eqts(n, vector<string>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> eqts[i][j];
        }
    }
    vector<double> vals(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vals[i];
    }
    int m;
    cin >> m;
    vector<vector<string>> qrs(m, vector<string>(2));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> qrs[i][j];
        }
    }
    Solution obj;
    for (const auto &x : obj.calcEquation(eqts, vals, qrs))
    {
        cout << x << ", ";
    }
    cout << endl;
    return 0;
}