#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int minCost(vector<int> &cost, int pos)
    {
        int minCost = INT_MAX;
        for (int i = 0; i <= pos; i++)
        {
            minCost = min(minCost, cost[i]);
        }
        return minCost;
    }

public:
    vector<int> minCosts(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> swap(n);
        for (int i = n - 1; i >= 0; i--)
        {
            swap[i] = minCost(cost, i);
        }
        return swap;
    }
};
int main()
{
    vector<int> cost = {5, 3, 4, 1, 3, 2};
    Solution obj;
    for (int i : obj.minCosts(cost))
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}