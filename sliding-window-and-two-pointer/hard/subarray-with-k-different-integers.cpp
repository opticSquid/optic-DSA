#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int countSubArrsWithKDistinct(vector<int> &nums, int k)
    {
        int cnt = 0;
        unordered_map<int, int> mpp;
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            mpp[nums[r]]++;
            while (mpp.size() > k)
            {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                {
                    mpp.erase(nums[l]);
                }
                l++;
            }

            cnt += (r - l + 1);
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return countSubArrsWithKDistinct(nums, k) - countSubArrsWithKDistinct(nums, k - 1);
    }
};
int main()
{
    vector<int> vec = {1, 2, 1, 2, 3};
    int k = 2;
    Solution obj;
    cout << obj.subarraysWithKDistinct(vec, k) << endl;
    return 0;
}