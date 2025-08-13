#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (const auto &ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if (st.size() == 0)
                {
                    return false;
                }
                char c = st.top();
                st.pop();
                if ((ch == ')' && c == '(') || (ch == '}' && c == '{') || (ch == ']' && c == '['))
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
    Solution obj;
    return 0;
}