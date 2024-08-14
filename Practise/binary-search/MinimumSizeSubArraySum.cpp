#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int minlen = INT_MAX;
        int i = 0, j = 0;
        int sum = 0;
        while (j < n)
        {
            sum += nums[j];
            while (sum >= target)
            {
                sum -= nums[i];
                minlen = min(minlen, j - i + 1);
                i++;
            }
            j++;
        }
        return minlen == INT_MAX ? 0 : minlen;
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