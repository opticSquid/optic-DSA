#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1, maxLH = 0, maxRH = 0, res = 0;
        while (l <= r)
        {
            if (height[l] <= height[r])
            {
                if (height[l] >= maxLH)
                {
                    maxLH = height[l];
                }
                else
                {
                    res += maxLH - height[l];
                }
                l++;
            }
            else
            {
                if (height[r] >= maxRH)
                {
                    maxRH = height[r];
                }
                else
                {
                    res += maxRH - height[r];
                }
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