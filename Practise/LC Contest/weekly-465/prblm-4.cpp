#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<int>> inc_subs;
    void create_inc_subs(vector<int> notTake, vector<int> take)
    {
        if (notTake.size() == 0)
        {
            if (take.size() != 0)
            {
                inc_subs.push_back(take);
            }
            return;
        }

        vector<int> temp;
        temp.push_back(notTake[0]);
        notTake.erase(notTake.begin());
        create_inc_subs(notTake, take);

        if (take.size() == 0)
        {
            create_inc_subs(notTake, temp);
        }
        else if (temp[0] > take[take.size() - 1])
        {
            take.push_back(temp[0]);
            create_inc_subs(notTake, take);
        }
    }

public:
    int totalBeauty(vector<int> &nums)
    {
        inc_subs = {};
        vector<int> ntk;
        create_inc_subs(nums, ntk);
        unordered_map<int, vector<vector<int>>> mpp;
        for (const auto &subs : inc_subs)
        {
            int res = subs[0];
            for (int i = 1; i < subs.size(); i++)
            {
                res = __gcd(subs[i], res);
                if (res == 1)
                    break;
            }
            mpp[res].push_back(subs);
        }
        int val = 0;
        for (const auto [k, v] : mpp)
        {
            val += (k * mpp[k].size());
        }
        return val;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3};
    Solution obj;
    cout << obj.totalBeauty(nums) << endl;
    return 0;
}