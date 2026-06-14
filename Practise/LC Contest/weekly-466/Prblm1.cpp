#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool checkSame(vector<int> &nums, int *l, int *r)
    {
        for (int i = *l; i < *r; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }

public:
    int minOperations(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        return checkSame(nums, &l, &r) ? 0 : 1;
    }
};
int main()
{
    vector<int> vec = {1, 2};
    Solution obj;
    cout << obj.minOperations(vec) << endl;
    return 0;
}