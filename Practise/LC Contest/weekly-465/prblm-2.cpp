#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<int> best;
    int bestDiff = INT_MAX;
    void backtrack(int n, int k, int start, vector<int> &curr)
    {
        if (k == 1)
        {
            if (n >= start)
            {
                curr.push_back(n);
                check(curr);
                curr.pop_back();
            }
            return;
        }
        // go until sqrt(n)
        for (int i = start; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                curr.push_back(i);
                backtrack(n / i, k - 1, i, curr);
                curr.pop_back();
            }
        }
    }
    void check(vector<int> &curr)
    {
        int mn = *min_element(curr.begin(), curr.end());
        int mx = *max_element(curr.begin(), curr.end());
        if (mx - mn < bestDiff)
        {
            bestDiff = mx - mn;
            best = curr;
        }
    }

public:
    vector<int> minDifference(int n, int k)
    {
        vector<int> curr;
        backtrack(n, k, 1, curr);
        return best;
    }
};
int main()
{
    int n = 44, k = 3;
    Solution obj;
    // expected: res = [2,2,11]
    vector<int> res = obj.minDifference(n, k);
    for (int i : res)
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}