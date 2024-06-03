#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxArraySize(int arr[], int n, int idx, int prevSum, int prevMaxLen)
    {
        if (idx == n)
        {
            return prevMaxLen;
        }
        int currSum = prevSum + arr[idx];
        if (currSum % 2 == 0)
        {
            int currMaxLen = prev
        }
    }
};
int main()
{
    Solution obj;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    return 0;
}