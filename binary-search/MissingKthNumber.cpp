#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums, int k)
    {
        int l = 0, r = nums.size() - 1;
        // trying to find the spot from where kth integer is missing
        while (l <= r)
        {
            int mid = (l + r) / 2;
            // find how many numbers are missing
            // +1 because array starts from 0 but our counting starts from 1
            int missing = nums[mid] - (mid + 1);
            if (missing < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        // return the missing number
        return k + r + 1;
        // or this can be returned too
        // Here, we will be replacing (r+1) with l as from above we see
        // l = (r+1)
        // So, below line also gives us the same result
        // return l+k;
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
    cout << obj.missingNumber(arr, k) << endl;
    return 0;
}