#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minEneryRequired(vector<int> &heights)
    {
        if (heights.empty())
        {
            return 0;
        }
        int n = heights.size();
        int prev1, prev2 = 0;
        int le, re;
        for (int i = 1; i < n; i++)
        {
            le = prev1 + abs(heights[i] - heights[i - 1]);
            re = INT_MAX;
            if (i > 1)
            {
                re = prev2 + abs(heights[i] - heights[i - 2]);
            }
            prev2 = prev1;
            prev1 = min(le, re);
        }
        return prev1;
    }
};
int main()
{
    vector<int> heights = {2, 1, 3, 5, 4};
    Solution obj;
    cout << obj.minEneryRequired(heights) << endl;
    return 0;
}