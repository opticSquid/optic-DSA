#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(int i, int dp[])
    {
        if (i <= 1)
        {
            if (i >= 0)
            {
                dp[i] = 1;
                return dp[i];
            }
            else
            {
                return 1;
            }
        }
        else
        {
            int l, r;
            if (dp[i - 1] == -1)
            {
                l = f(i - 1, dp);
            }
            else
            {
                l = dp[i - 1];
            }
            if (dp[i - 2] == -1)
            {
                r = f(i - 2, dp);
            }
            else
            {
                r = dp[i - 2];
            }
            dp[i] = l + r;
            return dp[i];
        }
    }

public:
    int climbStairs(int n)
    {
        int dp[n + 1];
        memset(dp, -1, sizeof(int) * (n + 1));
        int s = 0;
        s += f(n, dp);
        return s;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution obj;
    cout << obj.climbStairs(n) << endl;
    return 0;
}