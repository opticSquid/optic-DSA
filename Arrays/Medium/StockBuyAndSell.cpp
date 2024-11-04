#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int maxProf = 0, minPrc = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            minPrc = min(minPrc, prices[i]);
            maxProf = max(maxProf, prices[i] - minPrc);
        }
        return maxProf;
    }
};
int main()
{
    Solution obj;
    return 0;
}