#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int max = -99;
        int p = 0;
        int r, w;
        for (int i = 1; i <= 22; i++)
        {
            cin >> r;
            cin >> w;
            w *= 20;
            if (r + w > max)
            {
                max = r + w;
                p = i;
            }
        }
        cout << p << endl;
    }
    return 0;
}
