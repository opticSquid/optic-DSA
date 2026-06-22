#include <bits/stdc++.h>

using namespace std;
class Solution
{
private:
    int solve(int i, vector<int> &arr, vector<int> &dp)
    {
        if (i < 0)
        {
            return 0;
        }
        if (i == 0)
        {
            return arr[0];
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int t = arr[i] + solve(i - 2, arr, dp);
        int nt = solve(i - 1, arr, dp);
        return dp[i] = max(t, nt);
    }

public:
    int maximumNonAdjacentSum(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(n - 1, arr, dp);
    }
};
int main()
{
    vector<int> arr{2, 1, 4, 9, 16, 10, 20};
    Solution obj;
    cout << "max sum: " << obj.maximumNonAdjacentSum(arr) << endl;
    return 0;
}