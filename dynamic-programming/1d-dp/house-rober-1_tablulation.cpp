#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick += dp[i - 2];
            }
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[nums.size() - 1];
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