// see solution: https://leetcode.com/problems/longest-palindromic-substring/solutions/4212564/beats-96-49-5-different-approaches-brute-force-eac-dp-ma-recursion
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    string expandFromCenter(string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n <= 1)
        {
            return s;
        }
        string maxStr = s.substr(0, 1);
        for (int i = 0; i < n - 1; i++)
        {
            string odd = expandFromCenter(s, i, i);
            string even = expandFromCenter(s, i, i + 1);
            if (odd.size() > maxStr.size())
            {
                maxStr = odd;
            }
            if (even.size() > maxStr.size())
            {
                maxStr = even;
            }
        }
        return maxStr;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.longestPalindrome(s) << endl;
    return 0;
}