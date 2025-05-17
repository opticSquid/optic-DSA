#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
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
    vector<int> findNLI(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
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
    vector<int> findPLEI(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
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
    long long sumSubarrayMins(vector<int> &arr)
    {
        vector<int> nsi = findNSI(arr);
        vector<int> psei = findPSEI(arr);
        long long total = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int ni = nsi[i];
            int pi = psei[i];
            total = (total + ((ni - i) * (i - pi) * 1ll * arr[i]));
        }
        return total;
    }

    long long sumSubarrayMaxs(vector<int> &arr)
    {
        vector<int> nli = findNLI(arr);
        vector<int> plei = findPLEI(arr);
        long long total = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int ni = nli[i];
            int pi = plei[i];
            total = total + ((ni - i) * (i - pi) * 1ll * arr[i]);
        }
        return total;
    }

public:
    long long subArrayRanges(vector<int> &nums)
    {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
int main()
{
    Solution obj;
    return 0;
}