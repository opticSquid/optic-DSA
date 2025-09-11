#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void f(vector<int> &nums, int i, vector<int> &subseq, vector<vector<int>> &res)
    {
        if (i >= nums.size())
        {
            res.push_back(subseq);
            return;
        }
        subseq.push_back(nums[i]);
        f(nums, i + 1, subseq, res);
        subseq.pop_back();
        f(nums, i + 1, subseq, res);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> subSeq;
        vector<vector<int>> res;
        f(nums, 0, subSeq, res);
        return res;
    }
};
int main()
{
    Solution obj;
}