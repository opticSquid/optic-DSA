#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(int hNo, vector<int> &nums, vector<int> &dp)
    {
        if (hNo == 0)
        {
            dp[hNo] = nums[hNo];
            return nums[hNo];
        }
        else if (hNo < 0)
        {
            return 0;
        }
        else if (dp[hNo] != -1)
        {
            return dp[hNo];
        }
        else
        {
            int pick = nums[hNo] + f(hNo - 2, nums, dp);
            int notPick = f(hNo - 1, nums, dp);
            dp[hNo] = max(pick, notPick);
            return dp[hNo];
        }
    }

public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return f(nums.size() - 1, nums, dp);
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    Solution obj;
    cout << obj.rob(vec) << endl;
    return 0;
}