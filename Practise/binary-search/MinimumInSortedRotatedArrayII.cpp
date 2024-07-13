#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        int l = 0, r = n - 1, minimum = INT_MAX;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            // to deal with duplicates
            if (nums[l] == nums[mid] && nums[mid] == nums[r])
            {
                l++;
                r--;
            }
            else if (nums[l] <= nums[mid])
            {
                minimum = min(minimum, nums[l]);
                l = mid + 1;
            }
            else
            {
                minimum = min(minimum, nums[mid]);
                r = mid - 1;
            }
        }
        return minimum;
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
    cout << obj.findMin(nums) << endl;
    return 0;
}