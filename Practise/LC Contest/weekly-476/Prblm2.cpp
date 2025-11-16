#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minLengthAfterRemovals(string s)
    {
        unordered_map<char, int> mp;
        for (const char &c : s)
        {
            mp[c]++;
        }
        return abs(mp['a'] - mp['b']);
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.minLengthAfterRemovals(s) << endl;
    return 0;
}