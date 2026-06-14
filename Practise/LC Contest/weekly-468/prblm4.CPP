#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    long long findMaxMinDiff(vector<int> &nums, int l, int r)
    {
        if (l > r || l < 0 || r >= nums.size())
        {
            return 0ll;
        }
        else if (l == r)
        {
            return nums[l];
        }
        else
        {
            int min_ele = INT_MAX;
            int max_ele = INT_MIN;
            for (int i = l; i <= r; i++)
            {
                if (nums[i] < min_ele)
                {
                    min_ele = nums[i];
                }
                if (nums[i] > max_ele)
                {
                    max_ele = nums[i];
                }
            }
            return (long long)max_ele - min_ele;
        }
    }

public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        int l = 0, r = nums.size() - 1;
        int min_ele_idx, max_ele_idx;
        long long res = 0ll;
        while (k-- && l <= r)
        {
            vector<int> tmp(5);
            tmp[0] = findMaxMinDiff(nums, l, r);
            tmp[1] = findMaxMinDiff(nums, l + 1, r);
            tmp[2] = findMaxMinDiff(nums, l - 1, r);
            tmp[3] = findMaxMinDiff(nums, l, r + 1);
            tmp[4] = findMaxMinDiff(nums, l, r - 1);
            res += *max_element(tmp.begin(), tmp.end());
            l++;
            r--;
        }
        return res;
    }
};
int main()
{
    vector<int> nums = {1, 3, 2};
    int k = 2;
    Solution obj;
    cout << obj.maxTotalValue(nums, k) << endl;
    return 0;
}