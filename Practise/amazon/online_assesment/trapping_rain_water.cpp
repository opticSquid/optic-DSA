#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &heights)
    {
        int left = 0, right = heights.size() - 1;
        int maxLeft = 0, maxRight = 0, res = 0;
        while (left <= right)
        {
            if (heights[left] <= heights[right])
            {
                if (heights[left] >= maxLeft)
                {
                    maxLeft = heights[left];
                }
                else
                {
                    res += maxLeft - heights[left];
                }
                left++;
            }
            else
            {
                if (heights[right] >= maxRight)
                {
                    maxRight = heights[right];
                }
                else
                {
                    res += maxRight - heights[right];
                }
                right--;
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