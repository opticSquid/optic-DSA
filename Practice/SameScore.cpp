#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxOperations(vector<int> &nums)
    {
        int counter = 1;
        int target = nums[0] + nums[1];
        for (int i = 2; i <= nums.size() - 2; i += 2)
        {
            if (nums[i] + nums[i + 1] == target)
            {
                counter++;
            }
            else
            {
                break;
            }
        }
        return counter;
    }
};
int main()
{
    vector<int> nums1 = {3, 2, 1, 4, 5};
    vector<int> nums2 = {3, 2, 6, 1, 4};
    vector<int> nums3 = {1, 1, 1, 1, 1, 1};
    Solution obj;
    // cout << obj.maxOperations(nums1) << endl;
    // cout << obj.maxOperations(nums2) << endl;
    cout << obj.maxOperations(nums3) << endl;
    return 0;
}