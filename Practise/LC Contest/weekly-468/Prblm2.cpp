#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        int min_ele = INT_MAX;
        int max_ele = INT_MIN;
        for (const int &i : nums)
        {
            if (i < min_ele)
            {
                min_ele = i;
            }
            if (i > max_ele)
            {
                max_ele = i;
            }
        }
        return (long long)(max_ele - min_ele) * k;
    }
};
int main()
{
    Solution obj;
    return 0;
}