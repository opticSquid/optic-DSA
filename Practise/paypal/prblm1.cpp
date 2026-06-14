#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long getMinimumCost(vector<int> &arr)
    {
        int n = arr.size();
        long ic = 0l;
        for (int i = 1; i < n; i++)
        {
            long d = arr[i] - arr[i - 1];
            ic += d * d;
        }

        long best = LONG_MAX;
        for (int i = 1; i < n; i++)
        {
            long a = arr[i - 1];
            long b = arr[i];
            long oc = (a - b) * 1l * (a - b);

            double mid = (a + b) / 2.0;
            long x1 = floor(mid);
            long x2 = ceil(mid);
            for (long x : {x1, x2})
            {
                long nc = (a - x) * (a - x) + (b - x) * (b - x);
                long total = ic - oc + nc;
                best = min(best, total);
            }
        }
        return best;
    }
};
int main()
{
    vector<int> v = {4, 7, 1, 4};
    Solution obj;
    cout << obj.getMinimumCost(v);
    return 0;
}