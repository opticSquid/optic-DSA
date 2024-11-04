#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool slidingWindow(vector<int> &nums, int target, int size)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int mx = INT_MIN;
        while (j < n)
        {
            sum += nums[j];
            if (j - i + 1 == size)
            {
                mx = max(mx, sum);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return mx >= target;
    }

public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int minLen = 0;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (slidingWindow(nums, target, mid))
            {
                r = mid - 1;
                minLen = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return minLen;
    }
};
int main()
{
    int target;
    cin >> target;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.minSubArrayLen(target, nums) << endl;
    return 0;
}