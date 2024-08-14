#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // graph will be in the format:
        // src1 = {dst1,time1}, {dst5,time5}
        // src2 = {dst3,time3}, {dst4,time4}
        vector<pair<int, int>> graph[n];
        for (const auto &it : roads)
        {
            graph[it[0]].push_back({it[1], it[2]});
        }
        // pq will be in the form {eta_to_current_node,current_node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // every node will have ETA of INFINITYin start
        vector<int> eta(n, INT_MAX);
        // there will be 0 ways to reach a node at start
        vector<int> ways(n, 0);
        // source will have ETA 0 and will have 1 way to reach it
        eta[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        int mod = (int)(1e9 + 7);
        while (!pq.empty())
        {
            int eta_2_curr_node = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (const auto &adjNodes : graph[node])
            {
                int adjNode = adjNodes.first;
                int time = adjNodes.second;
                // This ‘if’ condition signifies that this is the first
                // time we’re coming with this short distance, so we push
                // in PQ and keep the no. of ways the same.
                if (eta_2_curr_node + time < eta[adjNode])
                {
                    eta[adjNode] = eta_2_curr_node + time;
                    ways[adjNode] = ways[node];
                    pq.push({eta_2_curr_node + time, adjNode});
                }
                // If we again encounter a node with the same short distance
                // as before, we simply increment the no. of ways.
                else if (eta_2_curr_node + time == eta[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        // Finally, we return the no. of ways to reach
        // (n-1)th node modulo 10^9+7.
        return ways[n - 1] % mod;
    }
};
int main()
{
    int intersections, num_roads;
    cin >> intersections >> num_roads;
    vector<vector<int>> matrix(num_roads, vector<int>(3));
    for (int i = 0; i < num_roads; i++)
    {
        int src, dst, time;
        cin >> src >> dst >> time;
        matrix[i] = {src, dst, time};
    }
    Solution obj;
    cout << obj.countPaths(intersections, matrix) << endl;
    return 0;
}