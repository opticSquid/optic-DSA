#include <bits/stdc++.h>
using namespace std;
int countSum(vector<int> v, int l, int r)
{
    int res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (i != j)
            {
                int sum = v[i] + v[j];
                if (sum >= l && sum <= r)
                {
                    res++;
                }
            }
        }
    }
    return res;
}
int main()
{
    int n, x, l, r;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    cin >> l >> r;
    cout << countSum(v, l, r);
    return 0;
}