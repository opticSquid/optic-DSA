#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int prefixsum = 0, n = nums.size(), cnt = 0;
        //! important
        mp.insert({0, 1});
        for (int i = 0; i < n; i++)
        {
            prefixsum += nums[i];
            cnt += mp[prefixsum - k];
            mp[prefixsum]++;
        }
        return cnt;
    }
};
int main()
{
    Solution obj;
    return 0;
}