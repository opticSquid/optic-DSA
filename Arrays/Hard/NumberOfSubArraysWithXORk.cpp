#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ctr = 0;
        int xorr = 0;
        map<int, int> mapp;
        mapp[xorr]++;
        for (int i = 0; i < n; i++)
        {
            xorr ^= nums[i];
            int x = xorr ^ k;
            ctr += mapp[x];
            mapp[xorr]++;
        }
        return ctr;
    }
};
int main()
{
    Solution obj;
    return 0;
}
