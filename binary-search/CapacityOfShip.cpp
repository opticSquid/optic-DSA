#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool check_if_possible_to_ship(vector<int> &weights, int total_days, int capacity)
    {
        int d = 1, load = 0;
        for (int weight : weights)
        {
            // if adding additional load exceed capacity
            // then put that load on next day
            if (load + weight > capacity)
            {
                d++;
                // optimization: if d has already exceeded target date
                // immidietly return false no need to iterate rest of array
                if (d > total_days)
                    return false;
                load = weight;
            }
            // if remaining capacity add on the same day
            else
            {
                load += weight;
            }
        }
        return true;
    }

public:
    int ship_capacity(vector<int> &weights, int days)
    {
        // l = max(weight), r = sum of elements of weight vector
        int l = *max_element(weights.begin(), weights.end()),
            r = accumulate(weights.begin(), weights.end(), 0);
        while (l <= r)
        {
            int mid = (l + r) / 2;
            // if it is poosible to ship
            // with 'mid' capacity in target days..
            if (check_if_possible_to_ship(weights, days, mid))
            {
                // try with a decreased capacity
                r = mid - 1;
            }
            else
            {
                // if capacity is too less to meet target days
                // increase capacity
                l = mid + 1;
            }
        }
        return l;
    }
};
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
    int d;
    cin >> d;
    Solution obj;
    cout << obj.ship_capacity(arr, d) << endl;
    return 0;
}