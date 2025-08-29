#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(int i, int dp[])
    {
        if (i <= 1)
        {
            return 1;
        }
        else
        {
            int l, r;
            if (dp[i - 1] != -1)
            {
                l = dp[i - 1];
            }
            else
            {
                l = f(i - 1, dp);
            }
            if (dp[i - 2] != -1)
            {
                r = dp[i - 2];
            }
            else
            {
                r = f(i - 2, dp);
            }
            return dp[i] = l + r;
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