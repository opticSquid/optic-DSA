#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        int n = arr.size();
        long sum = 0;
        int maxLen = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == 0)
            {
                maxLen = i + 1;
            }
            else if (mp.find(sum) != mp.end())
            {
                maxLen = max(maxLen, i - mp.at(sum));
            }
            else
            {
                mp.insert({sum, i});
            }
        }
        return maxLen;
    }
};
int main()
{
    Solution obj;
    return 0;
}