#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reverseDegree(string s)
    {
        int sum = 0;
        for (int i = 1; i <= s.length(); i++)
        {
            char c = s[i - 1];
            int org_pos = c - 'a' + 1;
            sum += (27 - org_pos) * i;
        }
        return sum;
    }
};
int main()
{
    Solution obj;
    return 0;
}