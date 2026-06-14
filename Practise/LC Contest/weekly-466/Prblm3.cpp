#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long bowlSubarrays_Naive(vector<int> &nums)
    {
        const int n = nums.size();
        stack<int> st;
        vector<int> lftGrtrIdx(n, -1);
        for (int l = 0; l < n; l++)
        {
            while (!st.empty() && nums[st.top()] < nums[l])
            {
                st.pop();
            }
            if (!st.empty())
            {
                lftGrtrIdx.at(l) = st.top();
            }
            st.push(l);
        }
        while (!st.empty())
        {
            st.pop();
        }
        vector<int> r8GrtrIdx(n, n);
        for (int r = n - 1; r >= 0; r--)
        {
            while (!st.empty() && nums[st.top()] < nums[r])
            {
                st.pop();
            }
            if (!st.empty())
            {
                r8GrtrIdx.at(r) = st.top();
            }
            st.push(r);
        }
        long long cnt = 0ll;
        for (int i = 0; i < n; i++)
        {
            if (lftGrtrIdx[i] != -1 && r8GrtrIdx[i] != n)
            {
                cnt++;
            }
        }
        return cnt;
    }
    long long bowlSubarrays_optimized(vector<int> &nums)
    {
        long long ans = 0;
        stack<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!s.empty() && nums[s.top()] < nums[i])
            {
                s.pop();
                if (!s.empty())
                {
                    ans++;
                }
            }
            s.push(i);
        }

        return ans;
    }
};
int main()
{
    vector<int> vec = {2, 5, 3, 1, 4};
    Solution obj;
    cout << obj.bowlSubarrays_Naive(vec) << endl;
    return 0;
}