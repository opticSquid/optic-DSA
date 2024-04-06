#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int findFloor(vector<int> &a, int n, int x)
    {
        int l = 0, r = n - 1, res = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (a[mid] <= x)
            {
                res = a[mid];
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        };
        return res;
    }
    int findCeil(vector<int> &a, int n, int x)
    {
        int l = 0, r = n - 1, res = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (a[mid] >= x)
            {
                res = a[mid];
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }

public:
    pair<int, int> findFloorCeil(vector<int> &a, int n, int x)
    {
        return {findFloor(a, n, x), findCeil(a, n, x)};
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
    pair<int, int> res = obj.findFloorCeil(arr, n, k);
    cout << "left: " << res.first << ", right: " << res.second << endl;
    return 0;
}