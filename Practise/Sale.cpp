#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sales[n];
        for (int i = 0; i < n; i++)
        {
            cin >> sales[i];
        }
        int max = -99;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sales[i] > max)
            {
                max = sales[i];
            }
            sum += sales[i];
        }
        cout << sum + max << endl;
    }
    return 0;
}
