#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int smallestAbsent(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            if (nums[0] < 0)
            {
                return 1;
            }
            else
            {
                return nums[0] + 1;
            }
        }
        int avg = 0;
        unordered_set<int> s;
        int maxEle = INT_MIN;
        for (const auto &i : nums)
        {
            avg += i;
            if (i > 0)
            {
                s.insert(i);
            }
            maxEle = max(maxEle, i);
        }
        avg /= n;
        avg = avg < 0 ? 0 : avg;
        for (int i = avg + 1; i < maxEle; i++)
        {
            if (s.find(i) == s.end())
            {
                return i;
            }
        }
        return maxEle + 1 < 0 ? 1 : maxEle + 1;
    }
};
int main()
{
    vector<int> vec = {0, 0};
    Solution obj;
    cout << obj.smallestAbsent(vec) << endl;
    return 0;
}