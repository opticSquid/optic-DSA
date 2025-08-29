#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    // Function to calculate the minimum number of elements to form the target sum
    int minimumElementsUtil(vector<int> &arr, int ind, int T, vector<vector<int>> &dp)
    {

        // Base case: If we're at the first element
        if (ind == 0)
        {
            // Check if the target sum is divisible by the first element
            if (T % arr[0] == 0)
                return T / arr[0]; // If yes, return the quotient as the answer
            else
                return 1e9; // Otherwise, return a very large value to indicate it's not possible
        }

        // If the result for this index and target sum is already calculated, return it
        if (dp[ind][T] != -1)
            return dp[ind][T];

        // Calculate the minimum elements needed without taking the current element
        int notTaken = 0 + minimumElementsUtil(arr, ind - 1, T, dp);

        // Calculate the minimum elements needed by taking the current element
        int taken = 1e9; // Initialize 'taken' to a very large value
        if (arr[ind] <= T)
            taken = 1 + minimumElementsUtil(arr, ind, T - arr[ind], dp);

        // Store the minimum of 'notTaken' and 'taken' in the DP array and return it
        return min(notTaken, taken);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        // Create a DP (Dynamic Programming) table with n rows and T+1 columns and initialize it with -1
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
            {
                dp[0][i] = i / coins[0];
            }
            else
            {
                dp[0][i] = 1e9;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int am = 0; am <= amount; am++)
            {
                int ntk = dp[i - 1][am];
                int tk = 1e9;
                if (coins[i] <= am)
                {
                    tk = 1 + dp[i][am - coins[i]];
                }
                dp[i][am] = min(ntk, tk);
            }
        }
        int ans = dp[n - 1][amount];
        if (ans >= 1e9)
        {
            return -1;
        }
        return ans;
    }
};
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution obj;
    cout << obj.coinChange(coins, amount) << endl;
    return 0;
}