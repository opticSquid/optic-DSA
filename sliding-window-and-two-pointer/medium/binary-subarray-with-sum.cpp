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
            sum += nums[r];
            while (sum > goal)
            {
                sum -= nums[l];
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int subArrsLEGoal = countSubArrsWithSumLEGoal(nums, goal);
        int subArrsLEGoalMinus1 = countSubArrsWithSumLEGoal(nums, (goal - 1));
        return subArrsLEGoal - subArrsLEGoalMinus1;
    }
};
int main()
{
    Solution obj;
    return 0;
}