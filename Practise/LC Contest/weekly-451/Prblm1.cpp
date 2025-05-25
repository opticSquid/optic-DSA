#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long minCuttingCost(int n, int m, int k)
    {
        long long cost = 0ll;
        if (n > k)
        {
            cost = k * (long long)(n - k);
        }
        else if (m > k)
        {
            cost = k * (long long)(m - k);
        }
        return cost;
    }
};
int main()
{
    Solution obj;
    return 0;
}