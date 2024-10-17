#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ctr = 0;
        for (int i = 0; i < n; i++)
        {
            int xorr = 0;
            for (int j = i; j < n; j++)
            {
                xorr ^= nums[j];
                if (xorr == k)
                {
                    ctr++;
                }
            }
        }
        return ctr;
    }
};
int main()
{
    Solution obj;
    return 0;
}
