#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProf = 0, minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxProf = max(maxProf, prices[i] - minPrice);
        }
        return maxProf;
    }
};
int main()
{
    vector<int> vec = {2, 4, 1};
    Solution obj;
    cout << obj.maxProfit(vec) << endl;
    return 0;
}