#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int beautySum(string s)
    {
        map<char, int> mp;
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            mp.clear();
            for (int j = i; j < n; j++)
            {
                mp[s[j]]++;
                int lf = INT_MAX, mf = INT_MIN;
                for (auto it : mp)
                {
                    lf = min(it.second, lf);
                    mf = max(it.second, mf);
                }
                ans += mf - lf;
            }
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    return 0;
}