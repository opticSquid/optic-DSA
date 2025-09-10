#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        const int n = s.size();
        if (k > n || k == 0)
        {
            return -1;
        }
        unordered_map<char, int> dump;
        // if not possible case is encountered, we would return maxLen=-1 as indicated in question
        int maxLen = -1;
        int l = 0, r = 0;
        while (r < n)
        {
            dump[s[r]]++;
            while (dump.size() > k)
            {
                dump[s[l]]--;
                if (dump[s[l]] == 0)
                {
                    dump.erase(s[l]);
                }
                l++;
            }
            if (dump.size() == k)
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
    string s;
    int k;
    cin >> s >> k;
    cout << obj.longestKSubstr(s, k) << endl;
    return 0;
}