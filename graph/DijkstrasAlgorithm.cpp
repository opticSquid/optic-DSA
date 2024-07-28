#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // set will store in the format {dist,node}.
        // storage format is very important because we want to compare by distance
        // a pair is compared by its first element by default
        // set keeps elements in ascending order by default
        set<pair<int, int>> s;
        vector<int> dist(V, 1e9);
        // setting the distance of source -> source as 0 in set
        s.insert({0, S});
        // setting the distance of source -> source as 0 in dist vector
        dist[S] = 0;
        while (!s.empty())
        {
            pair<int, int> first_ele = *(s.begin());
            int node = first_ele.second;
            int distance = first_ele.first;
            s.erase(first_ele);
            // for all the adj nodes of the current node
            for (vector<int> adjNodes : adj[node])
            {
                int adjNode = adjNodes[0];
                int wt = adjNodes[1];
                // if the distance from source to current node + weight to adJ Node
                // is less than prevly calculated distance
                if (distance + wt < dist[adjNode])
                {
                    // erase the previously calculated distance
                    s.erase({dist[adjNode], adjNode});
                    // insert the newly calculated minimum distance
                    s.insert({distance + wt, adjNode});
                    dist[adjNode] = distance + wt;
                }
            }
        }
        // retunr the vector of distances
        return dist;
    }
};
int main()
{
    // v = vertices, e = edges, s = source node
    int v = 3, e = 3, s = 2;
    // every entry is in the form {node, weight}
    vector<vector<int>> adj[] = {{{1, 1}, {2, 6}},
                                 {{0, 1}, {2, 3}},
                                 {{0, 6}, {1, 3}}};

    Solution obj;
    vector<int> res = obj.dijkstra(v, adj, s);
    for (int i = 0; i < res.size(); i++)
    {
        cout << "distance of " << s << " -> " << i << " = " << res[i] << endl;
    }
    return 0;
}