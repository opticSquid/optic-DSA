#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries, int x)
    {
        int n = nums.size();
        vector<int> hash;
        for (int i = 0; i < n; i++)
        {
            int k = nums[i];
            if (k == x)
            {
                hash.push_back(i);
            }
        }
        vector<int> res;
        for (int i : queries)
        {
            if (i > hash.size())
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(hash[i - 1]);
            }
        }
        return res;
    }
};
int main()
{
    vector<int> nums = {1, 3, 1, 7};
    vector<int> q = {1, 3, 2, 4};
    int x = 1;
    Solution obj;
    vector<int> res = obj.occurrencesOfElement(nums, q, x);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}