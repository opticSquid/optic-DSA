#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> ump;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                ump[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++)
        {
            if (ump.find(nums1[i]) != ump.end())
            {
                res[i] = ump[nums1[i]];
            }
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}