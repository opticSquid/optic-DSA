#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0, right = n - 1, res = 0, maxLeft = 0, maxRight = 0;
        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= maxLeft)
                {
                    maxLeft = height[left];
                }
                else
                {
                    res += maxLeft - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] >= maxRight)
                {
                    maxRight = height[right];
                }
                else
                {
                    res += maxRight - height[right];
                }
                right--;
            }
        }
        return res;
    }
};
int main()
{
    vector<int> vec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution obj;
    cout << obj.trap(vec) << endl;
    return 0;
}