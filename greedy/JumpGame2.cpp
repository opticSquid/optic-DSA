#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size(), jumps = 0, l = 0, r = 0;
        while (r < n - 1)
        {
            int far = 0;
            for (int idx = l; idx <= r; idx++)
            {
                far = max(far, idx + nums[idx]);
            }
            l = r + 1;
            r = far;
            jumps++;
        }
        return jumps;
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
    cout << obj.jump(nums) << endl;
    return 0;
}