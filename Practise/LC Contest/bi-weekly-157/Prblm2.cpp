#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubstrings(string word)
    {
        if (word.size() < 4)
        {
            return 0;
        }
        if (word.size() == 4)
        {
            if (word[0] == word[3])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int cnt = 0;
        int i = 0;
        while (i < word.size())
        {
            int j = i + 3;
            while (j < word.size())
            {
                if (word[i] == word[j])
                {
                    cnt++;
                    i = j + 1;
                    j = j + 4;
                }
                else
                {
                    j++;
                }
            }
            i++;
        }
        return cnt;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.maxSubstrings(s) << endl;
    return 0;
}