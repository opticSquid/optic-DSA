#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int maxLen = 0;
        int l = 0, r = 0, zeros = 0;
        while (r < nums.size())
        {
            if (nums[r] == 0)
            {
                zeros++;
            }
            while (zeros > k)
            {
                if (nums[l] == 0)
                {
                    zeros--;
                }
                l++;
            }
            if (zeros <= k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<int> vec;
    for (char c : s)
    {
        if (c == '[' || c == ',' || c == ']')
            continue;
        vec.push_back(c - '0');
    }
    Solution obj;
    cout << obj.longestOnes(vec, k) << endl;
    return 0;
}