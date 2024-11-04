#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int br = INT_MAX;
        // find the break point
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                br = i;
                break;
            }
        }
        // check if break point found
        if (br != INT_MAX)
        {
            // if found
            // find the min number in range br+1 to n-1
            int minIdx, minNum = INT_MAX;
            for (int i = n - 1; i > br; i--)
            {
                // minimum number in the right half which is greater than the break point
                if (nums[i] > nums[br])
                {
                    swap(nums[i], nums[br]);
                    break;
                }
            }
            // reverse the right half
            reverse(nums.begin() + br + 1, nums.end());
        }
        else
        {
            // break point does not exist
            // this is the last permutation
            // so, for the next iteration we will come to the first iteration
            reverse(nums.begin(), nums.end());
        }
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
    obj.nextPermutation(nums);
    // Next Permutation
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}