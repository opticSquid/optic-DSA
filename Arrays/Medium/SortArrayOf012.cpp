#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            switch (nums[mid])
            {
            case 0:
                swap(nums[low], nums[mid]);
                mid++;
                low++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[high], nums[mid]);
                high--;
                break;
            default:
                break;
            }
        }
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution obj;
    obj.sortColors(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}