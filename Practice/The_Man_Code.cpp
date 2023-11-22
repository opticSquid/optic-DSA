#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, max = 0, min = 0;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            if (i % 2 == 0)
            {
                max++;
            }
            else
            {
                min++;
            }
        }
        cout << max << " " << min << endl;
    }
    return 0;
}
