#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        unordered_map<int, int> mp;
        // implementing sliding window technique to generate all substrings
        // Iterate through substring lengths (1 to string length)
        for (int n = 1; n <= s.length(); n++)
        {
            // Iterate through the string to create windows of size n
            for (int i = 0; i < s.length() - n + 1; i++)
            {
                // itenrate through each character in current window
                for (int j = 0; j < n; j++)
                {
                    cout << s[i + j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}