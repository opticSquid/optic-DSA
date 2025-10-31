#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int mx_len = 0;
        unordered_set<int> vis;
        for (int i = 0; i < nums.size(); i++)
        {
            int evn_cnt = 0;
            int od_cnt = 0;
            int len = 0;
            vis.clear();
            for (int j = i; j < nums.size(); j++)
            {
                if (vis.find(nums[j]) == vis.end())
                {
                    if (nums[j] % 2 == 0)
                    {
                        evn_cnt++;
                    }
                    else
                    {
                        od_cnt++;
                    }
                    vis.insert(nums[j]);
                }
                if (evn_cnt == od_cnt)
                {
                    len = j - i + 1;
                }
            }
            mx_len = max(mx_len, len);
        }
        return mx_len;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 2};
    Solution obj;
    cout << obj.longestBalanced(nums) << endl;
    return 0;
}