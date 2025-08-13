#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i], more = target - nums[i];
            if (mp.find(more) != mp.end())
            {
                return {i, mp[more]};
            }
            else
            {
                mp[x] = i;
            }
        }
        return {};
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
    int target;
    cin >> target;
    Solution obj;
    for (int i : obj.twoSum(vec, target))
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}