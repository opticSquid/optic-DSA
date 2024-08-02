#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            int more = target - x;
            if (mp.find(more) != mp.end())
            {
                return {i, mp[more]};
            }
            mp[x] = i;
        }
        return {};
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    Solution obj;
    for (int i : obj.twoSum(arr, target))
    {
        cout << i << " ";
    };
    return 0;
}