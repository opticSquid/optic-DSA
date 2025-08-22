#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int rob_pvt(vector<int> &nums)
    {
        int dp_i2 = 0, dp_i1 = nums[0], curr = nums[0];
        for (int i = 1; i < nums.size(); i++)
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
        int l = nums[nums.size() - 1];
        nums.pop_back();
        int res_without_last = rob_pvt(nums);
        // considering nums can be 1 element vector after 1st removal it becomes empty
        if (!nums.empty())
        {
            nums.erase(nums.begin());
        }
        nums.push_back(l);
        int res_without_first = rob_pvt(nums);
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