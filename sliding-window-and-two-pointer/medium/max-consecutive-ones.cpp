#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int zeros = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] == 0)
                    zeros++;
                else if (zeros <= k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                else
                    break;
            }
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