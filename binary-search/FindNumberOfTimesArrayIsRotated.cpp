#include <bits/stdc++.h>
using namespace std;
int findNumberOfRotations(vector<int> &arr)
{
    // number of rotations in a sorted array can be found
    // by finding the index of the min element in the array
    int n = arr.size(), minimum = INT_MAX, min_index = 0;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        // left half is sorted
        if (arr[l] <= arr[mid])
        {
            if (arr[l] < minimum)
            {
                minimum = arr[l];
                min_index = l;
            }
            // eliminate left half
            l = mid + 1;
        }
        // right half is sorted
        else
        {
            if (arr[mid] < minimum)
            {
                minimum = arr[mid];
                min_index = mid;
            }
            // eliminate right half
            r = mid - 1;
        }
    }
    return min_index;
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