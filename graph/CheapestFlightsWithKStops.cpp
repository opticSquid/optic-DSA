#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // creating a graph out of the flight paths
        // every item contains {to, price}
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        // {stops,{node,cost}}
        queue<pair<int, pair<int, int>>> q;
        vector<int> costs(n, INT_MAX);
        q.push({0, {src, 0}});
        costs[src] = 0;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int currCity = it.second.first;
            int currCost = it.second.second;
            if (stops > k)
            {
                continue;
            }
            for (const auto &[nextCity, nextCost] : adj[currCity])
            {
                if (currCost + nextCost < costs[nextCity] && stops <= k)
                {
                    costs[nextCity] = currCost + nextCost;
                    q.push({stops + 1, {nextCity, currCost + nextCost}});
                }
            }
        }
        if (costs[dst] == INT_MAX)
        {
            return -1;
        }
        return costs[dst];
    }
};
int main()
{
    int num_cities;
    int flight_paths;
    vector<vector<int>> flights(flight_paths);
    for (int i = 0; i < flight_paths; i++)
    {
        int from, to, price;
        cin >> from >> to >> price;
        flights[i].push_back(from);
        flights[i].push_back(to);
        flights[i].push_back(price);
    }
    int src, dst, max_stops;
    cin >> src >> dst >> max_stops;
    Solution obj;
    cout << obj.findCheapestPrice(num_cities, flights, src, dst, max_stops) << endl;
    return 0;
}