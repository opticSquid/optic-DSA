#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        const int mod = 100000;
        // pq will be in the format {steps, num}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // {calculated_num, distance}
        unordered_map<int, int> distance;
        pq.push({0, start});
        distance.insert({start, 0});
        while (!pq.empty())
        {
            int num = pq.top().second;
            int curr_steps = pq.top().first;
            pq.pop();
            // if the end node is reached
            if (num == end)
            {
                return curr_steps;
            }
            for (int i : arr)
            {
                int node = (num * i) % mod;
                // if the number was generated earlier or not
                if (distance.find(node) != distance.end())
                {
                    // the number was generated earlier check for better distance
                    if (curr_steps + 1 < distance[node])
                    {
                        distance[node] = curr_steps + 1;
                        pq.push({curr_steps + 1, node});
                    }
                }
                else
                {
                    // the number was not generated earlier
                    distance.insert({node, curr_steps + 1});
                    pq.push({curr_steps + 1, node});
                }
            }
        }
        // number is not attainable
        return -1;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int start, end;
    cin >> start >> end;
    Solution obj;
    cout << obj.minimumMultiplications(arr, start, end) << endl;
    return 0;
}