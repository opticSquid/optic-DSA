#include <bits/stdc++.h>
using namespace std;
int sudoExponent(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= mid;
        // exponent already exceeded target
        // no point in continuing
        if (ans > m)
            return 2;
    }
    // mid is the nth root of m
    if (ans == m)
        return 1;
    // mid raised to n is less than m;
    return 0;
}
int squareRootInLogN(int n, int m)
{
    if (m <= 0)
        return 0;
    int l = 1, r = m;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        // in between check for the numbers which are not perfect squares
        if (sudoExponent(mid, n, m) == 1)
        {
            return mid;
        }
        else if (sudoExponent(mid, n, m) == 0)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    cout << squareRootInLogN(n, m) << endl;
    return 0;
}