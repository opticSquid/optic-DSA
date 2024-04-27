#include <bits/stdc++.h>
using namespace std;
int peak_element(vector<int> &arr)
{
    int n = arr.size();
    // edge cases
    if (n == 1)
    {
        return arr[0];
    }
    if (arr[0] > arr[1])
    {
        return 0;
    }
    if (arr[n - 1] > arr[n - 2])
    {
        return n - 1;
    }
    int l = 1, r = n - 2;
    // main loop
    while (l <= r)
    {
        int mid = (l + r) / 2;

        // larger than both left and right elements
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        // in left so, increasing order
        else if (arr[mid] > arr[mid - 1])
        {
            l = mid + 1;
        }
        // in right so, decreasing order
        else
        {
            r = mid - 1;
        }
    }
    // Dummy return
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
    cout << peak_element(arr) << endl;
    return 0;
}