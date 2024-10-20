#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> stringSequence(string target)
    {
        vector<string> res;
        for (int i = 0; i < target.size(); i++)
        {
            string ans;
            if (i == 0)
                ans = "";
            else
                // copy i+1 characters from 0 position of target
                ans = target.substr(0, i + 1);
            for (char c = 'a'; c <= target[i]; c++)
            {
                if (ans.empty())
                {
                    ans = c;
                }
                else
                {
                    ans[ans.size() - 1] = c;
                }
                res.push_back(ans);
            }
        }
        return res;
    }
};
int main()
{
    string target;
    cin >> target;
    Solution obj;
    for (string s : obj.stringSequence(target))
    {
        cout << s << endl;
    }
    return 0;
}