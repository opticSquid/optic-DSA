#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int evenNumberBitwiseORs(vector<int> &nums)
    {
        int res = 0;
        for (int i : nums)
        {
            if (i % 2 == 0)
            {
                cout << i << endl;
                res |= i;
            }
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}