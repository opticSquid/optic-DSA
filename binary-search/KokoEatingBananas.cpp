#include <bits/stdc++.h>
using namespace std;
int max_ele(int n, vector<int> &arr)
{
    int max_el = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        max_el = max(max_el, arr[i]);
    }
    return max_el;
}
size_t calculate_hours(vector<int> &arr, int n, int hourly)
{
    size_t total_hours = 0;
    for (int i = 0; i < n; i++)
    {
        total_hours += ceil((double)(arr[i]) / (double)(hourly));
    }
    return total_hours;
}
int min_number_of_bananas(vector<int> &arr, int h)
{
    int n = arr.size();
    int max = max_ele(n, arr);
    int l = 1, r = max;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int hrs = calculate_hours(arr, n, mid);
        if (hrs <= (size_t)h)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
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
    int h;
    cin >> h;
    cout << min_number_of_bananas(arr, h) << endl;
    return 0;
}