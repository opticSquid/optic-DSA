#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
        {
            return x;
        }
        int l = 1, r = x;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (mid * mid == x)
            {
                return mid;
            }
            else if (mid * mid < x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return round(r);
    }
};
int main()
{
    int x;
    cin >> x;
    Solution obj;
    cout << obj.mySqrt(x) << endl;
    return 0;
}