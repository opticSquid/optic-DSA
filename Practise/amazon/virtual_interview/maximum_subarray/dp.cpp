#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int solve(vector<int> &nums, int i, bool mustPick, vector<vector<int>> &dp)
    {
        if (i >= nums.size())
        {
            return mustPick ? 0 : -1e5;
        }
        else if (dp[mustPick][i] != -1)
        {
            return dp[mustPick][i];
        }
        else if (mustPick)
        {
            return max(0, dp[mustPick][i] = nums[i] + solve(nums, i + 1, true, dp));
        }
        else
        {
            return dp[mustPick][i] = max(solve(nums, i + 1, false, dp), nums[i] + solve(nums, i + 1, true, dp));
        }
    }

public:
    int maxSubArray(vector<int> &nums)
    {
        vector<vector<int>> dp(2, vector(nums.size(), -1));
        return solve(nums, 0, false, dp);
    }
    int maxSubArray_tabulation(vector<int> &nums)
    {
        vector<vector<int>> dp(2, vector(nums.size(), -1));
        dp[0][0] = dp[1][0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[1][i] = max(nums[i], nums[i] + dp[1][i - 1]);
            dp[0][i] = max(dp[0][i - 1], dp[1][i]);
        }
        return dp[0].back();
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.maxSubArray_tabulation(nums) << endl;
    return 0;
}