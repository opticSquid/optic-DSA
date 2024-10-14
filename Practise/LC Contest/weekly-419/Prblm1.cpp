#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    static bool sortByFreq(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }
        else
        {
            return a.second > b.second;
        }
    }
    int xSum(vector<int> &nums, int l, int r, int x)
    {
        unordered_map<int, int> mp;
        for (int i = l; i <= r; i++)
        {
            // if key exists
            if (mp.find(nums[i]) != mp.end())
            {
                mp[nums[i]]++;
            }
            else
            {
                mp[nums[i]] = 1;
            }
        }
        vector<pair<int, int>> freq(mp.begin(), mp.end());
        sort(freq.begin(), freq.end(), Solution::sortByFreq);
        int ans = 0;
        for (int i = 0; i < freq.size() && i < x; i++)
        {
            ans += freq[i].first * freq[i].second;
        }
        return ans;
    }

public:
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<int> answer;
        for (int i = 0; i < (n - k + 1); i++)
        {
            if (k != x)
            {
                answer.push_back(xSum(nums, i, (i + k - 1), x));
            }
            else
            {
                int ans = 0;
                for (int j = i; j <= (i + k - 1); j++)
                {
                    ans += nums[j];
                }
                answer.push_back(ans);
            }
        }
        return answer;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k, x;
    cin >> k >> x;
    Solution obj;
    for (int i : obj.findXSum(nums, k, x))
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}