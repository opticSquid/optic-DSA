#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int ps = 0, cnt = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            ps += nums[i];
            cnt += mp[ps - k];
            mp[ps]++;
        }
        return cnt;
    }
};
int main()
{
    Solution obj;
    return 0;
}