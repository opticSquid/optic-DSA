#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string lexGreaterPermutation(string s, string target)
    {
        sort(s.begin(), s.end());
        do
        {
            if (s > target)
            {
                return s;
            }
        } while (std::next_permutation(s.begin(), s.end()));
        return s;
    }
};
int main()
{
    Solution obj;
    cout << obj.lexGreaterPermutation("abc", "bba") << endl;
    return 0;
}