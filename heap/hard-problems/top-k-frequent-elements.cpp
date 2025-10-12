#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        if (nums.size() == k)
        {
            return nums;
        }
        unordered_map<int, int> mp;
        for (const auto &n : nums)
        {
            mp[n]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> hp;
        for (const auto &it : mp)
        {
            hp.push({it.second, it.first});
            if (hp.size() > k)
            {
                hp.pop();
            }
        }
        vector<int> res;
        res.reserve(k);
        while (!hp.empty())
        {
            res.push_back(hp.top().second);
            hp.pop();
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}