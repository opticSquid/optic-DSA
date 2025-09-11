#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int traverse(int prev, int i, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i == nums.size())
        {
            return 0;
        }
        if (dp[i][prev + 1] != -1)
        {
            return dp[i][prev + 1];
        }
        int len = 0 + traverse(prev, i + 1, nums, dp);
        if (prev == -1 || nums[i] > nums[prev])
        {
            len = max(len, 1 + traverse(i, i + 1, nums, dp));
        }
        return dp[i][prev + 1] = len;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return traverse(-1, 0, nums, dp);
    }
};
int main()
{
    int n;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution obj;
    cout << obj.lengthOfLIS(nums) << endl;
    return 0;
}