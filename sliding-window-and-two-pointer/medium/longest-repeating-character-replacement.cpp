#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int l, r, maxF = 0, maxLen = 0;
        int hash[26];
        memset(hash, 0, 26 * sizeof(int));
        while (r < s.size())
        {
            hash[s[r] - 'A']++;
            maxF = max(maxF, hash[s[r] - 'A']);
            if ((r - l + 1 - maxF) > k)
            {
                hash[s[l] - 'A']--;
                maxF = 0;
                for (int i = 0; i < 26; i++)
                {
                    maxF = max(maxF, hash[i]);
                }
                l++;
            }
            if ((r - l + 1 - maxF) <= k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};
int main()
{
    Solution obj;
    return 0;
}