#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void maxChar(string x, char &m)
    {
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] > m)
            {
                m = x[i];
            }
        }
    }

public:
    string lastNonEmptyString(string s)
    {
        unordered_map<char, int> countMap;
        vector<char> orderKeeper;
        for (int i = 0; i < s.size(); i++)
        {
            if (countMap.find(s[i]) == countMap.end())
            {
                countMap[s[i]] = 1;
                orderKeeper.push_back(s[i]);
            }
            else
            {
                countMap[s[i]]++;
            }
        }
        string res;
        for (char c : orderKeeper)
        {
            if (countMap[c] % 2 != 0)
            {
                res += c;
            }
        }
        return res;
    }
    string unoptimized_working_lastNonEmptyString(string s)
    {
        string prev_string;
        char max = 'a';
        maxChar(s, max);
        int i = 0;
        while (s != "")
        {
            prev_string = s;
            for (char j = 'a'; j <= max; j++)
            {
                for (int i = 0; i < s.size(); i++)
                {
                    if (s[i] == j)
                    {
                        s.erase(i, 1);
                        break;
                    }
                }
            }
        }
        return prev_string;
    }
};
int main()
{
    string x;
    cin >> x;
    Solution obj;
    cout << obj.unoptimized_working_lastNonEmptyString(x) << endl;
    cout << obj.lastNonEmptyString(x) << endl;
}