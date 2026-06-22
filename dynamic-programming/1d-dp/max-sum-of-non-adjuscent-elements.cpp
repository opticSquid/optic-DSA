#include <bits/stdc++.h>

using namespace std;
class Solution
{

public:
    int maximumNonAdjacentSum(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return arr[0];
        }
        vector<int> dp(n, -1);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};
int main()
{
    vector<int> arr{2, 1, 4, 9, 16, 10, 20};
    Solution obj;
    cout << "max sum: " << obj.maximumNonAdjacentSum(arr) << endl;
    return 0;
}