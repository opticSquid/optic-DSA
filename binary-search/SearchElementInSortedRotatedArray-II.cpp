#include <bits/stdc++.h>
using namespace std;
bool searchInARotatedSortedArrayII(vector<int> &arr, int k)
{
    int n = arr.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == k)
        {
            return true;
        }
        // as the array may contain duplicates
        // there can be a special case where both the ends and the mid are same
        // there we will not be able to identify sorted part
        // so we will look inward to identify sorted part
        // we will increment left(l) and decrement right(r)
        // and continue to do so till this edge condition meet
        else if (arr[l] == arr[mid] && arr[r] == arr[mid])
        {
            l++;
            r--;
        }
        // left half is sorted
        else if (arr[l] <= arr[mid])
        {
            // check if target is located in left half
            if (arr[l] <= k && arr[mid] >= k)
            {
                // if found, eliminate right half
                r = mid - 1;
            }
            else
            {
                // if target not found in left half,eliminate left half
                l = mid + 1;
            }
        }
        // right half is sorted
        else if (arr[mid] <= arr[r])
        {
            // check if target is located in right half
            if (arr[mid] <= k && arr[r] >= k)
            {
                // if found, eliminate left half
                l = mid + 1;
            }
            else
            {
                // if target not found in right half, eliminate right half
                r = mid - 1;
            }
        }
    }
    return false;
}
int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    if (searchInARotatedSortedArrayII(arr, k) == 1)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}