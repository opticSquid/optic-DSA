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
    string infixToPrefix(string s)
    {
        reverse(s.begin(), s.end());
        for (char c : s)
        {
            // important
            if (c == '(')
            {
                c = ')';
            }
            if (c == ')')
            {
                c = '(';
            }
            // main part
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
                while (!st.empty() && st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                if (c == '^')
                {
                    while (!st.empty() && prec(c) <= prec(st.top()))
                    {
                        res += st.top();
                        st.pop();
                    }
                }
                else
                {
                    while (!st.empty() && prec(c) < prec(st.top()))
                    {
                        res += st.top();
                        st.pop();
                    }
                }
                st.push(c);
            }
        }
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}