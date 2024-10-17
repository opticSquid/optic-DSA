#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long ctr = 0;
        for (int i = 0; i < n; i++)
        {
            long aand = i;
            for (int j = i; j < n; j++)
            {
                aand &= nums[j];
                if (aand == k)
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
