#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int minEnergyJump(int i, vector<int> &heights, vector<int> &dp)
    {
        if (i == 0)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int le = minEnergyJump(i - 1, heights, dp) + abs(heights[i] - heights[i - 1]);
        int re = INT_MAX;
        if (i > 1)
        {
            re = minEnergyJump(i - 2, heights, dp) + abs(heights[i] - heights[i - 2]);
        }

        return dp[i] = min(le, re);
    }

public:
    int minEneryRequired(vector<int> &heights)
    {
        if (heights.empty())
        {
            return 0;
        }
        int n = heights.size();
        vector<int> dp(n, -1);
        return this->minEnergyJump(n - 1, heights, dp);
    }
};
int main()
{
    vector<int> heights = {2, 1, 3, 5, 4};
    Solution obj;
    cout << obj.minEneryRequired(heights) << endl;
    return 0;
}