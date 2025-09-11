#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int l = 0, r = heights.size() - 1;
        int res = 0;
        while (l <= r)
        {
            res = max(res, ((r - l) * min(heights[r], heights[l])));
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
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << obj.maxArea(heights) << endl;
    return 0;
}