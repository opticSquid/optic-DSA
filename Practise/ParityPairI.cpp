#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        bool res = true;
        if (nums.size() > 1)
        {

            for (int i = 0, j = i + 1; i < nums.size() - 1; i++, j++)
            {
                if ((nums[i] % 2 == 0 && nums[j] % 2 == 0) || (nums[i] % 2 != 0 && nums[j] % 2 != 0))
                {
                    res = false;
                    break;
                }
            }
        }
        return res;
    }
};
int main()
{
    vector<int> arr = {4, 3, 1, 6};
    Solution obj;
    cout << obj.isArraySpecial(arr) << endl;
    return 0;
}