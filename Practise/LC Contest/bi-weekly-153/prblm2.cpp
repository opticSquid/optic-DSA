#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int n = s.size();
        s = "1" + s + "1"; // Augmenting with '1' at both ends
        int maxSections = 0;

        vector<int> zeroBlocks, oneBlocks;

        int i = 0;
        while (i < s.size())
        {
            if (s[i] == '0')
            {
                int start = i;
                while (i < s.size() && s[i] == '0')
                    i++;
                if (s[start - 1] == '1' && s[i] == '1')
                { // Block surrounded by '1's
                    zeroBlocks.push_back(i - start);
                }
            }
            else
            {
                int start = i;
                while (i < s.size() && s[i] == '1')
                    i++;
                oneBlocks.push_back(i - start);
            }
        }

        // Count the original number of '1' sections
        maxSections = oneBlocks.size();

        for (int z : zeroBlocks)
        {
            maxSections = max(maxSections, (int)oneBlocks.size() + z - 1);
        }

        return maxSections;
    }
};
int main()
{
    Solution obj;
    cout << obj.maxActiveSectionsAfterTrade("1000100") << endl;
    return 0;
}