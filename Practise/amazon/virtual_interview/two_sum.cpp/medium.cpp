#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int diff = target - nums[i];
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                {
                    continue;
                }
                if (nums[j] == diff)
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};
int main()
{
    Solution obj;
    return 0;
}