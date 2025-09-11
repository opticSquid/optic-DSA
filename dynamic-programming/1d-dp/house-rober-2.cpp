#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int rob_pvt(vector<int> &nums, int start, int end)
    {
        if (start > end)
        {
            return 0;
        }
        if (start == end)
        {
            return nums[start];
        }
        int dp_i2 = 0, dp_i1 = nums[start], curr = nums[start];
        for (int i = start + 1; i <= end; i++)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick += dp_i2;
            }
            int notPick = dp_i1;
            curr = max(pick, notPick);
            dp_i2 = dp_i1;
            dp_i1 = curr;
        }
        return curr;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        int res_without_last = rob_pvt(nums, 0, n - 2);
        int res_without_first = rob_pvt(nums, 1, n - 1);
        return max(res_without_last, res_without_first);
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    Solution obj;
    cout << obj.rob(vec) << endl;
    return 0;
}