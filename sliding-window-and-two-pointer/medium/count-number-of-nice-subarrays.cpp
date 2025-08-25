#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int countSubArrsWithSumLEGoal(vector<int> &nums, int goal)
    {
        if (goal < 0)
        {
            return 0;
        }
        int l = 0, r = 0, sum = 0, cnt = 0;
        while (r < nums.size())
        {
            sum += (nums[r] % 2);
            while (sum > goal)
            {
                sum -= (nums[l] % 2);
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return countSubArrsWithSumLEGoal(nums, k) - countSubArrsWithSumLEGoal(nums, (k - 1));
    }
};
int main()
{
    Solution obj;
    return 0;
}