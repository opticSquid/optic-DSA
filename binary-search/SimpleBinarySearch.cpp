#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int target)
{
    // sort the given array
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (r + l) / 2;
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
    return -1;
}
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
    cout << search(arr, k) << endl;
}