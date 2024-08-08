#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st;
        int n = nums.size(), cnt, lngst = 0;
        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }
        for (int i : st)
        {
            // this can be the starting number of a sequence
            if (st.find(i - 1) == st.end())
            {
                cnt = 1;
                int x = i;
                // next consecutive number is found
                while (st.find(x + 1) != st.end())
                {
                    cnt++;
                    x = x + 1;
                }
                lngst = max(lngst, cnt);
            }
        }
        return lngst;
    }
};
int main()
{
    Solution obj;
    return 0;
}