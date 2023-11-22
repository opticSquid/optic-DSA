#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char p[n], e[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            // to UpperCase
            if ((int)p[i] > 96)
            {
                p[i] = (char)p[i] - 32;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cin >> e[i];
            // to UpperCase
            if ((int)e[i] > 96)
            {
                e[i] = (char)e[i] - 32;
            }
        }
    }
    return 0;
}
