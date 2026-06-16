#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minEneryRequired(vector<int> &heights)
    {
        if (heights.empty())
        {
            return 0;
        }
        int n = heights.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        int le, re;
        for (int i = 1; i < n; i++)
        {
            le = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            re = INT_MAX;
            if (i > 1)
            {
                re = dp[i - 2] + abs(heights[i] - heights[i - 2]);
            }
            dp[i] = min(le, re);
        }
        return dp[n - 1];
    }
};
int main()
{
    vector<int> heights = {2, 1, 3, 5, 4};
    Solution obj;
    cout << obj.minEneryRequired(heights) << endl;
    return 0;
}