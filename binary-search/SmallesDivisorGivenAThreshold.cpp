#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool check_sum(vector<int> &v, int x, int t)
    {
        int sum = 0;
        for (int i : v)
        {
            sum += ceil((double)i / (double)x);
        }
        return sum <= t;
    }

public:
    int smallestDivisor(vector<int> &v, int t)
    {
        int l = 1, r = *max_element(v.begin(), v.end());
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check_sum(v, mid, t))
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
    int k;
    cin >> k;
    Solution obj;
    cout << obj.smallestDivisor(arr, k) << endl;
    return 0;
}