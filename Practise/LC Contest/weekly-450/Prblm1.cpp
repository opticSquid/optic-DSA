#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int sum(int x)
    {
        int s = 0;
        while (x > 0)
        {
            int k = x % 10;
            s += k;
            x /= 10;
        }
        return s;
    }

public:
    int smallestIndex(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int s = sum(nums[i]);
            if (s == i)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> arr = {1, 10, 11};
    Solution obj;
    cout << obj.smallestIndex(arr) << endl;
    return 0;
}