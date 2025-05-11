#include <bits/stdc++.h>
using namespace std;
class MinStack
{
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() : mini(INT_MAX)
    {
    }

    void push(int value)
    {
        long long val = value;
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if (val < mini)
            {
                st.push(2 * val - mini);
                mini = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }
        long long el = st.top();
        st.pop();
        if (el < mini)
        {
            mini = 2 * mini - el;
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        long long el = st.top();
        if (el < mini)
        {
            return mini;
        }
        return el;
    }

    int getMin()
    {
        return mini;
    }
};
int main()
{
    MinStack obj;
    return 0;
}