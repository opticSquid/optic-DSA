#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool areConsecutive(char char1, char char2)
    {
        if (std::abs((char1 - 'a') - (char2 - 'a')) == 1)
        {
            return true;
        }
        if ((char1 == 'a' && char2 == 'z') || (char1 == 'z' && char2 == 'a'))
        {
            return true;
        }
        return false;
    }

public:
    string resultingString(string s)
    {
        string st = "";
        for (char c : s)
        {
            if (!st.empty() && areConsecutive(st.back(), c))
            {
                st.pop_back();
            }
            else
            {
                st.push_back(c);
            }
        }
        return st;
    }
};
int main()
{
    Solution obj;
    return 0;
}