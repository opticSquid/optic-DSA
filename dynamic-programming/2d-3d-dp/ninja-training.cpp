#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    // day: current day index
    // last: the activity chosen on day + 1 (0, 1, 2, or 3 for "none")
    int practice(int day, int last, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        // Base Case: If we reach the 0th day, pick the max points of the remaining allowed activities.
        if (day == 0)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    maxi = max(maxi, matrix[0][task]);
                }
            }
            return maxi;
        }
        // memoization check
        if (dp[day][last] != -1)
        {
            return dp[day][last];
        }
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                int points = matrix[day][task] + practice(day - 1, task, matrix, dp);
                maxi = max(maxi, points);
            }
        }
        // Store and return the result
        return dp[day][last] = maxi;
    }

public:
    int ninjaTraining(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return practice(n - 1, 3, matrix, dp);
    }
};
int main()
{
    // ith row represents merit points for {running, stealth, fighting}
    vector<vector<int>> matrix{{10, 40, 70},
                               {20, 50, 80},
                               {30, 60, 90}};
    Solution obj;
    cout << "max possible merit points: " << obj.ninjaTraining(matrix) << endl;
    return 0;
}