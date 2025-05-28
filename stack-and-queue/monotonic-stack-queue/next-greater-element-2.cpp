#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> next_greater_element(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }
            if (i < n)
            {
                if (!st.empty())
                {
                    res[i] = st.top();
                }
            }
            st.push(nums[i % n]);
        }
        return res;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution obj;
    vector<int> a = obj.next_greater_element(v);
    for (int i : a)
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}