#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int n = start ^ goal;
        int count = 0;
        while (n > 0)
        {
            count++;
            // every time the right most set bit turns to 0;
            // so we loop until all set bits are turned to 0
            n = n & (n - 1);
        }
        return count;
    }
};
int main()
{
    Solution obj;
    return 0;
}