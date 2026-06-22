#include <bits/stdc++.h>

using namespace std;
class Solution
{

public:
    int maximumNonAdjacentSum(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return arr[0];
        }
        int prevprev = 0;
        int prev = arr[0];
        int t, nt, cur;
        for (int i = 1; i < n; i++)
        {
            t = arr[i] + prevprev;
            nt = prev;
            cur = max(t, nt);
            prevprev = prev;
            prev = cur;
        }
        return prev;
    }
};
int main()
{
    vector<int> arr{2, 1, 4, 9, 16, 10, 20};
    Solution obj;
    cout << "max sum: " << obj.maximumNonAdjacentSum(arr) << endl;
    return 0;
}