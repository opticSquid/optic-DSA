#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto const &[num, freq] : mp)
        {
            minHeap.push({freq, num});
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        vector<int> res;
        res.reserve(k);
        while (!minHeap.empty())
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}