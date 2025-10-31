#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        unordered_set<int> hash(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size(); i++)
        {
            long long x = k * i;
            if (hash.find(x) == hash.end())
            {
                return x;
            }
        }
        return k * (nums.size() + 1);
    }
};
int main()
{
    Solution obj;
    return 0;
}