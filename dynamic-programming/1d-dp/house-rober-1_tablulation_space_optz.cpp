#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int dp_i2 = 0, dp_i1 = nums[0], curr = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick += dp_i2;
            }
            int notPick = dp_i1;
            curr = max(pick, notPick);
            dp_i2 = dp_i1;
            dp_i1 = curr;
        }
        return curr;
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
    cout << obj.rob(vec) << endl;
    return 0;
}