#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        // Initialize the maximum
        // index that can be reached
        int maxIndex = 0;

        // Iterate through each
        // index of the array
        for (int i = 0; i < nums.size(); i++)
        {
            // If the current index is greater
            // than the maximum reachable index
            // it means we cannot move forward
            // and should return false
            if (i > maxIndex)
            {
                return false;
            }

            // Update the maximum index
            // that can be reached by comparing
            // the current maxIndex with the sum of
            // the current index and the
            // maximum jump from that index
            maxIndex = max(maxIndex, i + nums[i]);
        }

        // If we complete the loop,
        // it means we can reach the
        // last index
        return true;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    Solution obj;
    cout << obj.canJump(vec) << endl;
    return 0;
}