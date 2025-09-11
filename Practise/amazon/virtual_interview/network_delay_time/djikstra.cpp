#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adjList(n);
        for (const auto &t : times)
        {
            adjList[t[0] - 1].push_back({t[1] - 1, t[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> records(n, INT_MAX);
        pq.push({0, k - 1});
        records[k - 1] = 0;
        while (!pq.empty())
        {
            const auto [latency, node] = pq.top();
            pq.pop();
            for (auto neigh : adjList[node])
            {
                int new_latency = latency + neigh.second;
                if (new_latency < records[neigh.first])
                {
                    pq.push({new_latency, neigh.first});
                    records[neigh.first] = new_latency;
                }
            }
        }
        int max_lat = *max_element(records.begin(), records.end());
        return max_lat == INT_MAX ? -1 : max_lat;
    }
};
int main()
{
    Solution obj;
    return 0;
}