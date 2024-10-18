#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        // we will consider x is repeating number, y is missing number
        long long n = arr.size();
        long long sn = (n * (n + 1)) / 2;
        // sum of squares of all natural numbers
        long long snPow2 = (n * (n + 1) * (2 * n + 1)) / 6;
        long long s = 0, sPow2 = 0;
        for (int i = 0; i < n; i++)
        {
            s += arr[i];
            sPow2 += (long long)arr[i] * (long long)arr[i];
        }
        long long xMinusy = s - sn;
        long long xPow2MinusyPow2 = sPow2 - snPow2;
        long long xPlusy = xPow2MinusyPow2 / xMinusy;
        long long x = (xPlusy + xMinusy) / 2;
        long long y = x - xMinusy;
        return {(int)x, (int)y};
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution obj;
    vector<int> res = obj.findTwoElement(arr);
    cout << "Repeating: " << res[0] << ", Missing: " << res[1] << endl;
    return 0;
}