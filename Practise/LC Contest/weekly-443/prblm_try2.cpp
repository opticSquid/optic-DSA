#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<string> generateSubSequences(string &s)
    {
        vector<string> temp;
        int left, right;
        // forward movement
        for (int winLen = 1; winLen <= s.size(); winLen++)
        {
            int l = 0;
            int r = l + winLen;
            while (r <= s.size())
            {
                string t = "";
                for (int i = l; i < r; i++)
                {
                    t += s[i];
                }
                temp.push_back(t);
                l++;
                r++;
            }
        }
        return temp;
    }
    bool isPalindrome(string &s)
    {
        int l = 0, r = s.size() - 1;
        while (l <= r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

public:
    int longestPalindrome(string s, string t)
    {
        vector s_subs = generateSubSequences(s);
        vector t_subs = generateSubSequences(t);
        int maxLen = INT_MIN;
        for (string j : t_subs)
        {
            if (isPalindrome(j))
            {
                maxLen = max(maxLen, (int)j.size());
            }
        }
        for (string i : s_subs)
        {
            if (isPalindrome(i))
            {
                maxLen = max(maxLen, (int)i.size());
            }
            for (string j : t_subs)
            {

                string temp = i + j;
                if (isPalindrome(temp))
                {
                    maxLen = max(maxLen, (int)temp.size());
                }
            }
        }
        return maxLen == INT_MIN ? 1 : maxLen;
    }
};
int main()
{
    string s = "abcde";
    string t = "ecdba";
    Solution obj;
    cout << obj.longestPalindrome(s, t) << endl;
    return 0;
}