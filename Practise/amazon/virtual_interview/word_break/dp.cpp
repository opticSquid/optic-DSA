#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        bool canSegment[n + 1];
        memset(canSegment, false, sizeof(canSegment));
        canSegment[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (canSegment[j] && wordSet.count(s.substr(j, i - j)))
                {
                    canSegment[i] = true;
                    break;
                }
            }
        }
        return canSegment[n];
    }
};
int main()
{
    Solution obj;
    return 0;
}