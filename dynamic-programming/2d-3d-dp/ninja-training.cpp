#include <bits/stdc++.h>
#include <cassert>
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
            return dp[day][last] = maxi;
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
        vector<vector<int>> dp(n, vector<int>(4, 0));
        // 0th index values - day = 0
        // for all possible task values
        for (int i = 0; i < 4; i++)
        {
            dp[0][i] = 0;
            // for all valid task values
            for (int j = 0; j < 3; j++)
            {
                // if the current task not equal to last task
                if (j != i)
                {
                    dp[0][i] = max(dp[0][i], matrix[0][j]);
                }
            }
        }
        // for rest
        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last < 4; last++)
            {
                dp[day][last] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {
                        int p = matrix[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], p);
                    }
                }
            }
        }
        return dp[n - 1][3];
    }
};
int main()
{
    // ith row represents merit points for {running, stealth, fighting}
    vector<vector<int>> matrix{{10, 40, 70},
                               {20, 50, 80},
                               {30, 60, 90}};
    Solution obj;
    assert(obj.ninjaTraining(matrix) == 210);
    matrix = {{70, 40, 10},
              {180, 20, 5},
              {200, 60, 30}};
    assert(obj.ninjaTraining(matrix) == 290);
    cout << "All tests passed" << endl;
    return 0;
}