#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(string s)
    {
        int maxOps = 0;
        for (const auto &c : s)
        {
            if (c != 'a')
            {
                maxOps = max(maxOps, ('z' - c) + 1);
            }
        }
        return maxOps;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.minOperations(s) << endl;
    return 0;
}