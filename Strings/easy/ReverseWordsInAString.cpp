#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void ltrim(string &s)
    {
        // int prev = s.length();
        // int cntr;
        // do
        // {
        //     cntr = 0;
        //     s.erase(s.find_first_not_of(' ') + 1);
        // } while (cntr != sp)
    }

    void rtrim(string &s)
    {
    }
    void innertrim(string &s)
    {
    }

public:
    string reverseWords(string s)
    {
        s += ' ';
        stack<string> st;
        string word = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else if (s[i] != ' ' && s[i + 1] == ' ')
            {
                word += s[i];
                st.push(word);
                word = "";
            }
            else
            {
                word += s[i];
            }
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
            ans += ' ';
        }
        // removes the last space that was added
        ans.erase(ans.end() - ((ans.length() > 0) ? 1 : 0), ans.end());
        return ans;
    }
};
int main()
{
    string s = "the sky is blue";
    Solution obj;
    // cout << obj.reverseWords(s) << endl;
    // s = "  hello world  ";
    // cout << obj.reverseWords(s) << endl;
    s = "a good   example";
    cout << obj.reverseWords(s) << endl;
    return 0;
}