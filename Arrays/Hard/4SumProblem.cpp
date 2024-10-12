#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                set<long long> hashset;
                for (int k = j + 1; k < n; k++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long frth = target - sum;
                    // 4th element is in the set
                    if (hashset.find(frth) != hashset.end())
                    {
                        vector<int> vec = {nums[i], nums[j], nums[k], (int)frth};
                        sort(vec.begin(), vec.end());
                        ans.insert(vec);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
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