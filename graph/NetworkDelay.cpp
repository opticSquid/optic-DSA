#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // convert to adjList
        vector<pair<int, int>> adjList[n];
        for (const vector<int> t : times)
        {
            adjList[t[0] - 1].push_back({t[1] - 1, t[2]});
        }
        // pq will be in the form {latency,node} with node with min latency at top
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // storing the effective latencies
        vector<int> latency(n, INT_MAX);
        // making latency 0 of source node
        pq.push({0, k - 1});
        latency[k - 1] = 0;
        while (!pq.empty())
        {
            int l = pq.top().first;
            int n = pq.top().second;
            pq.pop();
            for (const pair<int, int> it : adjList[n])
            {
                // if parent latency+node latency < previous calculated total latency
                // more efficeint path found add it to pq for recalculation and latency array
                if (l + it.second < latency[it.first])
                {
                    pq.push({l + it.second, it.first});
                    latency[it.first] = l + it.second;
                }
            }
        }
        int max_latency = *max_element(latency.begin(), latency.end());
        return max_latency != INT_MAX ? max_latency : -1;
    }
};
int main()
{
    int n, tn;
    cin >> n >> tn;
    vector<vector<int>> times(tn, vector<int>(3));
    for (int i = 0; i < tn; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        times[i] = {u, v, w};
    }
    int k;
    cin >> k;
    Solution obj;
    cout << obj.networkDelayTime(times, n, k) << endl;
    return 0;
}