#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty())
        {
            return "";
        }
        const int n = s.size(), m = t.size();
        int minLen = 1e9, sIdx = -1, l = 0, r = 0, cnt = 0;
        char hash[256] = {0};
        for (int i = 0; i < m; i++)
        {
            hash[t[i]]++;
        }
        while (r < n)
        {
            if (hash[s[r]] > 0)
            {
                cnt++;
            }
            hash[s[r]]--;
            while (cnt == m)
            {
                if (r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    sIdx = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0)
                {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return sIdx == -1 ? "" : s.substr(sIdx, minLen);
    }
};
int main()
{
    Solution obj;
    return 0;
}