#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool validSubstr(unordered_map<char, int> &mp, int k)
    {
        for (auto x : mp)
        {
            if (x.second >= k)
            {
                return true;
            }
        }
        return false;
    }

public:
    int numberOfSubstrings(string s, int k)
    {
        int n = s.size();
        int cnt = 0;
        for (int l = 0; l < n; l++)
        {
            unordered_map<char, int> mp;
            for (int r = l; r < n; r++)
            {
                mp[s[r]]++;
                if (validSubstr(mp, k))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    Solution obj;
    cout << obj.numberOfSubstrings(s, k) << endl;
    return 0;
}