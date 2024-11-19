#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDepth(string s)
    {
        int bal = 0;
        int maxD = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                bal += 1;
                maxD = max(bal, maxD);
            }
            else if (c == ')')
            {
                bal -= 1;
            }
        }
        return maxD;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.maxDepth(s) << endl;
    return 0;
}