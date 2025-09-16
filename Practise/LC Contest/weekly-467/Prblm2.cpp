#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> maxKDistinct(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        set<int> s;
        vector<int> res;
        for (int i = nums.size() - 1; i >= 0 && k > 0; i--)
        {
            if (s.find(nums[i]) == s.end())
            {
                res.push_back(nums[i]);
                s.insert(nums[i]);
                k--;
            }
        }
        return res;
    }
};
int main()
{
    vector<int> vec = {84, 93, 100, 77, 93};
    int k = 3;
    Solution obj;
    for (const int &i : obj.maxKDistinct(vec, k))
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}