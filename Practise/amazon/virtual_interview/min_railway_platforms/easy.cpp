#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        vector<pair<int, char>> timeline;
        int p = 0, maxP = INT_MIN;
        for (const auto &i : arr)
        {
            timeline.push_back({i, 'A'});
        }
        for (const auto &i : dep)
        {
            timeline.push_back({i, 'D'});
        }
        sort(timeline.begin(), timeline.end());
        for (const auto &t : timeline)
        {
            if (t.second == 'A')
            {
                p += 1;
                maxP = max(maxP, p);
            }
            else
            {
                p -= 1;
            }
        }
        return maxP;
    }
};
;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), dep(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> dep[i];
    }
    Solution obj;
    cout << obj.findPlatform(arr, dep) << endl;
    return 0;
}