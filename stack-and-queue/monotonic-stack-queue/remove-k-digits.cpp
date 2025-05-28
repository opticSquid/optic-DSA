#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string st;
        for (char c : num)
        {
            while (k > 0 && !st.empty() && (st.back() - '0') > (c - '0'))
            {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        st.resize(st.length() - k);

        size_t first_non_zero_pos = st.find_first_not_of('0');
        if (first_non_zero_pos == string::npos)
        {
            return "0";
        }
        return st.substr(first_non_zero_pos);
    }
};
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    Solution obj;
    cout << obj.removeKdigits(s, k) << endl;
    return 0;
}