#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> arr, int n, int x)
{
    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1, res = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        // may be an answer
        if (arr[mid] >= x)
        {
            res = mid;
            // look in the left if there are any matching elements
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
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
    cout << lowerBound(arr, n, k) << endl;
}