#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> arr, int n, int x)
{
    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1, res = n;
    while (l <= r)
    {
        // bit manipulation to divide by 2
        int mid = (l + r) >> 1;
        // may be an answer
        if (arr[mid] > x)
        {
            // look in the left for elements in the smaller index
            // for probable match
            res = mid;
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