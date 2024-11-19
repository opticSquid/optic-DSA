#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] < mp[s[i + 1]])
            {
                num -= mp[s[i]];
            }
            else
            {
                num += mp[s[i]];
            }
        }
        return num + mp[s.size() - 1];
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.romanToInt(s) << endl;
    return 0;
}