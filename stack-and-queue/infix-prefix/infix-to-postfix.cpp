#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    stack<char> st;
    string res;
    int prec(char c)
    {
        if (c == '^')
        {
            return 3;
        }
        else if (c == '/' || c == '*')
        {
            return 2;
        }
        else if (c == '+' || c == '-')
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

public:
    string infixToPostfix(string s)
    {
        for (char c : s)
        {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {
                res += c;
            }
            else if (c == '(')
            {
                st.push('(');
            }
            else if (c == ')')
            {
                while (st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && prec(c) <= prec(st.top()))
                {
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
    }
};
int main()
{
    Solution obj;
    return 0;
}