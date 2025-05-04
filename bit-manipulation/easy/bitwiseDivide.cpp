#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == divisor)
        {
            return 1;
        }
        bool neg = false;
        if ((dividend < 0 && divisor >= 0) || (dividend >= 0 && divisor < 0))
        {
            neg = true;
        }
        unsigned long n = dividend < 0 ? -(long long)dividend : dividend;
        unsigned long d = divisor < 0 ? -(long long)divisor : divisor;
        unsigned long quotient = 0;
        while (n >= d)
        {
            int cnt = 0;
            while (n >= (d << (cnt + 1)))
            {
                cnt++;
            }
            quotient += 1 << cnt;
            n -= d << cnt;
        }
        if (quotient > INT_MAX)
        {
            return neg ? INT_MIN : INT_MAX;
        }
        else
        {
            return neg ? -quotient : quotient;
        }
    }
};
int main()
{
    int d1, d2;
    cin >> d1 >> d2;
    Solution obj;
    cout << obj.divide(d1, d2) << endl;
    return 0;
}