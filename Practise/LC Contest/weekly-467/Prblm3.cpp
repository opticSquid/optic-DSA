#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<int> suSWithSum(const vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int sum = 1; sum <= k; sum++)
            {
                if (arr[i - 1] <= sum)
                {
                    dp[i][sum] = dp[i - 1][sum] || dp[i - 1][sum - arr[i - 1]];
                }
                else
                {
                    dp[i][sum] = dp[i - 1][sum];
                }
            }
        }
        if (!dp[n][k])
            return {};
        vector<int> indices;
        int sum = k, i = n;
        while (sum > 0 && i > 0)
        {
            if (dp[i - 1][sum])
            {
                i--;
            }
            else if (sum >= arr[i - 1] && dp[i - 1][sum - arr[i - 1]])
            {
                indices.push_back(i - 1);
                sum -= arr[i - 1];
                i--;
            }
            else
            {
                i--;
            }
        }

        reverse(indices.begin(), indices.end());
        return indices;
    }

    vector<int> cap(vector<int> &nums, int k, int iMax)
    {
        vector<int> tmp(nums);
        for (int i = 0; i < tmp.size(); i++)
        {
            tmp.at(i) = min(tmp.at(i), iMax);
        }
        return suSWithSum(tmp, k);
    }

public:
    vector<bool> subsequenceSumAfterCapping(vector<int> &nums, int k)
    {
        vector<bool> res(nums.size(), false);
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> subSum = cap(nums, k, i + 1);
            if (!subSum.empty())
            {
                for (const int &x : subSum)
                {
                    res.at(x) = true;
                }
                break;
            }
        }
        return res;
    }
};
int main()
{
    vector<int> vec = {4, 3, 2, 4};
    Solution obj;
    for (const bool &b : obj.subsequenceSumAfterCapping(vec, 5))
    {
        string r = b ? "true" : "false";
        cout << r << ",";
    }
    cout << endl;
    return 0;
}