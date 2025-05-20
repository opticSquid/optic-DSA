#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0);
        for (int i = 0; i <= n; ++i)
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
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