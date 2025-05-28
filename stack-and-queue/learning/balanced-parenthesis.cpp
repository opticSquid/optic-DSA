#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    stack<char> st;

public:
    bool isValid(string s)
    {
        for (char it : s)
        {
            if (it == '(' || it == '{' || it == '[')
            {
                st.push(it);
            }
            else
            {
                if (st.size() == 0)
                {
                    return false;
                }
                char ch = st.top();
                st.pop();
                if ((it == ')' && ch == '(') || (it == '}' && ch == '{') || (it == ']' && ch == '['))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    string res = obj.isValid(s) ? "true" : "false";
    cout << res << endl;
    return 0;
}