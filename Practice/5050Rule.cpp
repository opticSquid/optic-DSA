#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (x < 50)
        {
            cout << "Z" << endl;
        }
        else if (x >= 50 && y < 50)
        {
            cout << "F" << endl;
        }
        else
        {
            cout << "A" << endl;
        }
    }
    return 0;
}
