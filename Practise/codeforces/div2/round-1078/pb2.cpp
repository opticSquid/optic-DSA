#include <bits/stdc++.h>

using namespace std;

long long solve(vector<int> &b, vector<int> &c, const int &n, const int &t, const int &y)
{
    long long mx = 0;
    for (int i = 0; i < n; i++)
    {
        long long res = b[i] + ((t - c[i]) * y);
        mx = max(mx, res);
    }
    return mx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<int> quo(n);
        for (int i = 0; i < n; i++)
        {
            quo[i] = b[i] / x;
        }
        int quo_sum = accumulate(quo.begin(), quo.end(), 0);
        cout << solve(b, quo, n, quo_sum, y) << "\n";
    }
    cout << endl;
    return 0;
}
