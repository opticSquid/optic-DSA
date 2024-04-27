#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int count_new_gas_stations(vector<int> &arr, long double dist)
    {
        int cnt = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            int gas_stations_in_btwn = (arr[i] - arr[i - 1]) / dist;
            // checking if this is perfectly divisible or not
            if ((arr[i] - arr[i - 1]) / dist == gas_stations_in_btwn * dist)
            {
                gas_stations_in_btwn--;
            }
            cnt += gas_stations_in_btwn;
        }
        return cnt;
    }

public:
    long double min_of_max_dist_btwn_gas_stations(vector<int> &arr, int k)
    {
        int n = arr.size();
        long double l = 0, r = 0;
        for (int i = 0; i < n - 1; i++)
        {
            r = max(r, (long double)arr[i + 1] - arr[i]);
        }
        long double diff = 1e-6;
        while (r - l > diff)
        {
            long double mid = (l + r) / 2.0;
            if (count_new_gas_stations(arr, mid) > k)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        return r;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << obj.min_of_max_dist_btwn_gas_stations(arr, k) << endl;
    return 0;
}