#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool checkSpecial(vector<int> &nums, int start, int end)
    {
        bool res = true;
        if (nums.size() > 1)
        {

            for (int i = start, j = i + 1; i < end; i++, j++)
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

public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<bool> res;
        for (auto it : queries)
        {
            res.push_back(checkSpecial(nums, it[0], it[1]));
        }
        return res;
    }
};
int main()
{
    vector<int> arr = {3, 4, 1, 2, 6};
    vector<vector<int>> queries = {{0, 4}};
    Solution obj;
    for (bool it : obj.isArraySpecial(arr, queries))
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}