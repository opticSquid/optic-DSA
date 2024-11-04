#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size(), res = INT_MIN;
        int prefix = 1, suffix = 1;
        for (int i = 0; i < n; i++)
        {
            prefix = prefix == 0 ? 1 : prefix;
            suffix = suffix == 0 ? 1 : suffix;
            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            res = max(res, max(prefix, suffix));
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}