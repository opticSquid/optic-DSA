#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> leaders(int n, int arr[])
    {
        int maxEle = arr[n - 1];
        vector<int> ans;
        ans.push_back(maxEle);
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] >= maxEle)
            {
                maxEle = arr[i];
                ans.push_back(maxEle);
            }
        }
        // just to match the test cases
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution obj;
    for (int i : obj.leaders(n, nums))
    {
        cout << i << " ";
    }
    return 0;
}