#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, roll = 1, sum = 0, a;
        cin >> n;
        a = n / 2;
        if (n % 2 == 0)
        {
            cout << a * 1 + a * 12 << endl;
        }
        else
        {
            cout << a * 1 + a * 12 + 6 << endl;
        }
    }
    return 0;
}