#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minEnergyRequired(vector<int> &heights, int k)
    {
        if (heights.empty() || k <= 0)
        {
            return 0;
        }
        int n = heights.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++)
        {
            // minimum enery for each step across all possible jumps
            int mnE = INT_MAX;
            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                {
                    int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                    mnE = min(mnE, jump);
                }
            }
            dp[i] = mnE;
        }
        return dp[n - 1];
    }
};
int main()
{
    vector<int> heights{15, 4, 1, 14, 15};
    Solution obj;
    cout << obj.minEnergyRequired(heights, 3) << endl;
    return 0;
}