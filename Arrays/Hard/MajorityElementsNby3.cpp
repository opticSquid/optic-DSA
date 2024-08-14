#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size(), cnt1 = 0, cnt2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && ele2 != nums[i])
            {
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if (cnt2 == 0 && ele1 != nums[i])
            {
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if (ele1 == nums[i])
            {
                cnt1++;
            }
            else if (ele2 == nums[i])
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele1)
                cnt1++;
            if (nums[i] == ele2)
                cnt2++;
        }
        int mini = int(n / 3) + 1;
        if (cnt1 >= mini)
            ans.push_back(ele1);
        if (cnt2 >= mini)
            ans.push_back(ele2);
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
    Solution obj;
    for (int i : obj.majorityElement(nums))
    {
        cout << i;
    }
    return 0;
}