#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findFirstAndLastOccurance(vector<int> &arr, int x)
    {
        int n = arr.size();
        vector<int> region(2, -1);
        // first occourance
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] == x)
            {
                region[0] = mid;
                // move left
                r = mid - 1;
            }
            else if (arr[mid] < x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        // last occourance
        l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] == x)
            {
                region[1] = mid;
                // move right
                l = mid + 1;
            }
            else if (arr[mid] < x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return region[0] == -1 ? 0 : region[1] - region[0] + 1;
    }
};
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    Solution obj;
    cout << obj.findFirstAndLastOccurance(arr, k) << endl;
    return 0;
}