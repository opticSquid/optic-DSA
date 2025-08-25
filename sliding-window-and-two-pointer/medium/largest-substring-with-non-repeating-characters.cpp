#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int l = 0;
        int maxL = 0;
        unordered_map<char, int> mp;
        for (int r = 0; r < n; r++)
        {
            if (mp.find(s[r]) != mp.end())
            {
                l = max(mp[s[r]] + 1, l);
            }
            maxL = max(maxL, (r - l + 1));
            mp[s[r]] = r;
        }
        return maxL;
    }
};
int main()
{
    Solution obj;
    return 0;
}