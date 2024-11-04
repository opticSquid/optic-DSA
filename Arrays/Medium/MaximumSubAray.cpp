#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // this is kadane's algorithm
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size(), maxSum = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum > maxSum)
            {
                maxSum = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxSum;
    }
};
int main()
{
    Solution obj;
    return 0;
}