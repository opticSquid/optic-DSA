#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int subsets = 1 << n;
        vector<vector<int>> ans;
        // going through each possible subset
        for (int num = 0; num < subsets; num++)
        {
            vector<int> a;
            // going through each element in the given array
            for (int i = 0; i < n; i++)
            {
                if (num && (1 << i))
                {
                    a.push_back(nums[i]);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    return 0;
}