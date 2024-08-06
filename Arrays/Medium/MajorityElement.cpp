#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // this is moore's voting algo
    int majorityElement(vector<int> &nums)
    {
        int el, cnt = 0, n = nums.size();
        // finding the majority element
        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                el = nums[i];
                cnt = 1;
            }
            else if (el == nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        int lim = n / 2;
        // resusing cnt variable for counting in this loop
        cnt = 0;
        // verifying if our finding of majority element was correct
        for (int i = 0; i < n; i++)
        {
            if (el == nums[i])
            {
                cnt++;
            }
        }
        return cnt > lim ? el : -1;
    }
};
int main()
{
    Solution obj;
    return 0;
}