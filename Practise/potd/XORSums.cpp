#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int include_exclude(vector<int> &nums, int index, int currentXor)
    {
        // Base case: when all elements have been considered
        if (index == nums.size())
        {
            return currentXor;
        }
        // Include nums[index] in the subset
        int include = include_exclude(nums, index + 1, currentXor ^ nums[index]);
        // Exclude nums[index] from the subset
        int exclude = include_exclude(nums, index + 1, currentXor);
        return include + exclude;
    }

public:
    int subsetXORSum(vector<int> &nums)
    {
        return include_exclude(nums, 0, 0);
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.subsetXORSum(nums) << endl;
    return 0;
}