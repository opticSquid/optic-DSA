#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int findLargestChange(vector<int> &coins, int M, int V)
    {
        int l = 0, r = M - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (coins[mid] <= V)
            {
                l = mid + 1;
            }
            else if (coins[mid] > V)
            {
                r = mid - 1;
            }
        }
        return r;
    }

public:
    int minCoins(vector<int> &coins, int M, int V)
    {
        sort(coins.begin(), coins.end());
        int coinNumber = 0;
        int remaining = V;
        while (remaining > 0)
        {
            int pointer = findLargestChange(coins, M, remaining);
            int numCoin = remaining / coins[pointer];
            coinNumber += numCoin;
            remaining %= coins[pointer];
        }
        return coinNumber;
    }
};
int main()
{
    int V, M;
    cin >> V >> M;
    vector<int> coins(M);
    for (int i = 0; i < M; i++)
    {
        cin >> coins[i];
    }
    Solution obj;
    cout << obj.minCoins(coins, M, V) << endl;
    return 0;
}