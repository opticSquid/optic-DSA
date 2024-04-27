#include <bits/stdc++.h>
using namespace std;
int findNumberOfRotations(vector<int> &arr)
{
    int n = arr.size(), minimum = INT_MAX;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        // as the array may contain duplicates
        // there can be a special case where both the ends and the mid are same
        // there we will not be able to identify sorted part
        // so we will look inward to identify sorted part
        // we will increment left(l) and decrement right(r)
        // and continue to do so till this edge condition meet
        if (arr[l] == arr[mid] && arr[r] == arr[mid])
        {
            l++;
            r--;
        }
        // left half is sorted
        else if (arr[l] <= arr[mid])
        {
            minimum = min(minimum, arr[l]);
            // eliminate left half
            l = mid + 1;
        }
        // right half is sorted
        else
        {
            minimum = min(minimum, arr[mid]);
            // eliminate right half
            r = mid - 1;
        }
    }
    return minimum;
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
    cout << findNumberOfRotations(arr) << endl;
    return 0;
}