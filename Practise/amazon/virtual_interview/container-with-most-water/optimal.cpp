#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int n = heights.size();
        int l = 0, r = n - 1;
        int res = 0;
        while (l <= r)
        {
            res = max(res, (r - l) * min(heights[r], heights[l]));
            if (heights[l] <= heights[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}