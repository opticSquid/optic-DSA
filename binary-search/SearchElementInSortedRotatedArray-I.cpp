#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == k)
        {
            return mid;
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
    return -1;
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
    cout << search(arr, n, k) << endl;
}