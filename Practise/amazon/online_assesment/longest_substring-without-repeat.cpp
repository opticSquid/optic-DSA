#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int l = 0, maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (mp.find(ch) != mp.end())
            {
                l = max(l, mp[ch] + 1);
            }
            mp[ch] = i;
            maxLen = max(maxLen, i - l + 1);
        }
        return maxLen;
    }
};
int main()
{
    Solution obj;
    return 0;
}