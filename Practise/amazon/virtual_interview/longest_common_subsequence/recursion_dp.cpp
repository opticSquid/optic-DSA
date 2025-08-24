#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &match)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        else if (match[i][j] != -1)
        {
            return match[i][j];
        }
        else if (s[i] == t[j])
        {
            return 1 + f(i - 1, j - 1, s, t, match);
        }
        else
        {
            return max(f(i - 1, j, s, t, match), f(i, j - 1, s, t, match));
        }
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> match(n, vector<int>(m, -1));
        return f(n - 1, m - 1, text1, text2, match);
    }
};
int main()
{
    Solution obj;
    return 0;
}