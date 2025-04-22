#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xor_sum = 0;
        for (int i : nums)
        {
            xor_sum ^= i;
        }
        return xor_sum;
    }
};
int main()
{
    Solution obj;
    return 0;
}