#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    /*
     * find next smaller index
     */
    vector<int> findNSI(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
    /*
     * find previous smaller or equal index
     */
    vector<int> findPSEI(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        vector<int> nsi = findNSI(arr);
        vector<int> psei = findPSEI(arr);
        int total = 0;
        int n = arr.size();
        int mod = (int)1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            int ni = nsi[i];
            int pi = psei[i];
            total = (total + ((ni - i) * (i - pi) * 1ll * arr[i]) % mod) % mod;
        }
        return total;
    }
};
int main()
{
    vector<int> arr = {11, 81, 94, 43, 3};
    Solution obj;
    cout << obj.sumSubarrayMins(arr) << endl;
    return 0;
}