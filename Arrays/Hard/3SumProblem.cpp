#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            // skipping duplicate values
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            // assigning two pointers
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    vector<int> tmp = {nums[i], nums[l], nums[r]};
                    sort(tmp.begin(), tmp.end());
                    ans.push_back(tmp);
                    l++;
                    r--;
                    // skipping duplicates
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
                else if (sum > 0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return ans;
    }
};
int main()
{
    int n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    Solution obj;
    for (vector<int> v : obj.threeSum(vec))
    {
        for (int i : v)
        {
            cout << i << ", ";
        }
        cout << "\n";
    }
    return 0;
}