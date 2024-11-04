#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            // skipping duplicates and skipping first element
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                // skipping duplicates
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int k = j + 1;
                int l = n - 1;
                while (k <= l)
                {
                    long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        // skip the duplicates:
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }
        return ans;
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
    for (vector<int> vec : obj.fourSum(nums, target))
    {
        for (int i : vec)
        {
            cout << i << ", ";
        }
        cout << endl;
    }
    return 0;
}