#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagramMySolution(string s, string t)
    {
        int n = s.size(), m = t.size();
        if (n != m)
            return false;
        unordered_map<char, int> smp;
        unordered_map<char, int> tmp;
        for (int i = 0; i < n; i++)
        {
            smp[s[i]]++;
            tmp[t[i]]++;
        }
        for (pair<char, int> sc : smp)
        {
            if (tmp.find(sc.first) != tmp.end())
            {
                if (tmp[sc.first] != sc.second)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> smp;
        for (char c : s)
        {
            smp[c]++;
        }
        for (char c : t)
        {
            if (smp.find(c) != smp.end())
                smp[c]--;
            else
                return false;
        }
        for (auto c : smp)
        {
            if (c.second != 0)
                return false;
        }
        return true;
    }
};
int main()
{
    string s, t;
    s = "anagram", t = "nagaram";
    Solution obj;
    cout << obj.isAnagram(s, t) << endl;
    return 0;
}