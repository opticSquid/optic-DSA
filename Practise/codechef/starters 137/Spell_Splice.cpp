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
        vector<pair<int, int>> spells(n);
        for (int i = 0; i < n; i++)
        {
            pair<int, int> s;
            cin >> s.first >> s.second;
            spells[i] = s;
        }
        int max_str = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int str = spells[i].first * spells[j].second + spells[i].second * spells[j].first;
                max_str = max(str, max_str);
            }
        }
        cout << max_str << endl;
    }
    return 0;
}
