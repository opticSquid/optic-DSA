#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<int> prevSmallerElementIndex(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
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

    vector<int> nextSmallerElementIndex(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> res(n, n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
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
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> prevSmallerIdx = prevSmallerElementIndex(heights);
        vector<int> nextSmallerIdx = nextSmallerElementIndex(heights);
        int n = heights.size();
        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int width = nextSmallerIdx[i] - prevSmallerIdx[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }
        return maxArea;
    }
};
int main()
{
    vector<int> heights = {2, 4};
    Solution obj;
    cout << obj.largestRectangleArea(heights) << endl;
    return 0;
}