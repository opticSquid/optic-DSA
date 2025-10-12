#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> maxCombinations(vector<int> &nums1, vector<int> &nums2, int k)
    {
        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end(), greater<int>());
        priority_queue<tuple<int, int, int>> mxHp;
        set<pair<int, int>> vis;
        mxHp.push({nums1[0] + nums2[0], 0, 0});
        vis.insert({0, 0});
        vector<int> result;

        while (k-- && !mxHp.empty())
        {
            auto [sum, i, j] = mxHp.top();
            mxHp.pop();
            result.push_back(sum);

            if (i + 1 < nums1.size() && vis.find({i + 1, j}) == vis.end())
            {
                mxHp.push({nums1[i + 1] + nums2[j], i + 1, j});
                vis.insert({i + 1, j});
            }

            if (j + 1 < nums2.size() && vis.find({i, j + 1}) == vis.end())
            {
                mxHp.push({nums1[i] + nums2[j + 1], i, j + 1});
                vis.insert({i, j + 1});
            }
        }
        return result;
    }
};
int main()
{
    Solution obj;
    return 0;
}