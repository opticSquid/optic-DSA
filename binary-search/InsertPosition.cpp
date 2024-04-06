#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, res = r;
        // searching for the element if element found return from here.
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    int k;
    cin >> k;
    Solution obj;
    cout << obj.searchInsert(arr, k) << endl;
}