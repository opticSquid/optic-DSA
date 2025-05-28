#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int celebrity(vector<vector<bool>> &mat)
    {
        stack<int> st;
        for (int i = 0; i < mat.size(); i++)
        {
            st.push(i);
        }
        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if (mat[a][b])
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }
        // potential celeb candidate
        int c = st.top();
        for (int i = 0; i < mat.size(); i++)
        {
            if (i == c)
            {
                continue;
            }
            // person does not know c but c knows the person
            // so, c can not be a celebrity
            if (!mat[i][c] || mat[c][i])
            {
                return -1;
            }
        }
        return c;
    }
};
int main()
{
    Solution obj;
    return 0;
}