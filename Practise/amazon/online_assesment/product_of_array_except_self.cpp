#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> res(n, 1);
        long long product = 1LL;
        for (int i = 0; i < n; i++)
        {
            res[i] = product;
            product *= nums[i];
        }
        product = 1LL;
        for (int i = n - 1; i >= 0; i--)
        {
            res[i] *= product;
            product *= nums[i];
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}