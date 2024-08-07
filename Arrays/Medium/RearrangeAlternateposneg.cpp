#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posI = 0, negI = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                ans[posI] = nums[i];
                posI += 2;
            }
            else
            {
                ans[negI] = nums[i];
                negI += 2;
            }
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    return 0;
}