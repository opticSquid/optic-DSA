#include <bits/stdc++.h>
using namespace std;
int squareRootInLogN(int n)
{
    if (n <= 0)
        return 0;
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        // in between check for the numbers which are not perfect squares
        if ((pow(mid, 2) < n && n < pow(mid + 1, 2)) || pow(mid, 2) == n)
        {
            return mid;
        }
        else if (pow(mid, 2) < n)
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
int squareRootInLogN_simple(int n)
{
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (pow(mid, 2) <= (long long)(n))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return r;
}
int main()
{
    int n;
    cin >> n;
    cout << squareRootInLogN_simple(n) << endl;
    return 0;
}