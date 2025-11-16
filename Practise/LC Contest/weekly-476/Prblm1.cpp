#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximizeExpressionOfThree(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int max_val = nums[n - 1];
        int min_val = nums[0];
        int sec_max = nums[n - 2];
        return max_val + sec_max - min_val;
    }
};
int main()
{
    vector<int> vec{-8, -8, -8};
    Solution obj;
    cout << obj.maximizeExpressionOfThree(vec) << endl;
    return 0;
}