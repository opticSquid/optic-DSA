#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int>
    twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        for (int i = 0; i < n; i++)
        {
            int rem = target - numbers[i];
            int l = i + 1, r = n - 1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (numbers[mid] == rem)
                {
                    return {i + 1, mid + 1};
                }
                else if (numbers[mid] > rem)
                {
                    r = mid - 1;
                }
                else if (numbers[mid] < rem)
                {
                    l = mid + 1;
                }
            }
        }
        return {};
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
    int target;
    cin >> target;
    Solution obj;
    for (int i : obj.twoSum(nums, target))
    {
        cout << i << " ";
    }
    return 0;
}