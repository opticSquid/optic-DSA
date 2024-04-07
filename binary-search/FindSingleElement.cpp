#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    // edge cases
    if (n == 1)
    {
        return arr[0];
    }
    else if (arr[0] != arr[1])
    {
        return arr[0];
    }
    else if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }
    int l = 1, r = n - 2;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        // single element
        if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }
        // criteria of being in left half
        else if (mid % 2 == 0 && arr[mid] == arr[mid + 1] || mid % 2 == 1 && arr[mid] == arr[mid - 1])
        {
            l = mid + 1;
        }
        // else you are right half
        else
        {
            r = mid - 1;
        }
    }
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
    cout << singleNonDuplicate(arr) << endl;
    return 0;
}