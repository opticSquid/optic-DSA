#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int balance = 0;
        string res = "";
        for (char c : s)
        {
            if (c == '(')
            {
                if (balance > 0)
                {
                    res += c;
                }
                balance++;
            }
            else if (c == ')')
            {
                balance--;
                if (balance > 0)
                {
                    res += c;
                }
            }
            else
            {
                return "";
            }
        }
        return res;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.removeOuterParentheses(s) << endl;
    return 0;
}