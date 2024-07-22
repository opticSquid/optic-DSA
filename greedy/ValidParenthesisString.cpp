#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkValidString(string s)
    {
        int mn = 0, mx = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                mn++;
                mx++;
            }
            else if (c == ')')
            {
                mn--;
                mx--;
            }
            else if (c == '*')
            {
                mn--;
                mx++;
            }

            if (mn < 0)
            {
                mn = 0;
            }
            if (mx < 0)
            {
                return false;
            }
        }
        return mn == 0;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.checkValidString(s) << endl;
    return 0;
}