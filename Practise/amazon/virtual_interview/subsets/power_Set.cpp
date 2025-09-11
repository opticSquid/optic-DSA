#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int subsets = 1 << n;
        vector<vector<int>> ans;
        for (int num = 0; num < subsets; num++)
        {
            vector<int> a;
            for (int i = 0; i < n; i++)
            {
                if (num & (1 << i))
                {
                    a.push_back(nums[i]);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3};
    Solution obj;
    obj.subsets(nums);
    return 0;
}