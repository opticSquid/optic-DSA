#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maxProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater());
        long long maxProd = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int x = nums[i];
                int y = nums[j];
                // both are odd, lsb is always same = 1, AND can never be 0
                if (x & 1 == 1 && y & 1 == 1)
                {
                    continue;
                }
                int cbit = x & y;
                if (cbit == 0)
                {
                    maxProd = max(maxProd, (long long)x * y);
                }
            }
        }
        return maxProd == 1 ? 0 : maxProd;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.maxProduct(nums) << endl;
    return 0;
}