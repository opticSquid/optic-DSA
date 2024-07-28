#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        if (start == end)
        {
            return 0;
        }
        const int mod = 100000;
        // pq will be in the format {steps, num}
        queue<pair<int, int>> q;
        // {calculated_num, distance}
        vector<int> distance(100000, 1e9);
        q.push({start, 0});
        distance[start] = 0;
        while (!q.empty())
        {
            int num = q.front().first;
            int curr_steps = q.front().second;
            q.pop();
            for (int i : arr)
            {
                int node = (num * i) % mod;
                // if the number was generated earlier or not
                if (curr_steps + 1 < distance[node])
                {
                    distance[node] = curr_steps + 1;
                    q.push({node, curr_steps + 1});
                    // Whenever we reach the end number
                    // return the calculated steps
                    if (node == end)
                        return curr_steps + 1;
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