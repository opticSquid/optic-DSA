#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    double _pow(double x, int n)
    {
        double ans = 1.00;
        while (n > 0)
        {
            if (n & 1)
            {
                ans *= x;
                n -= 1;
            }
            else
            {
                n /= 2;
                x *= x;
            }
        }
        return ans;
    }

public:
    double myPow(double x, int n)
    {
        if (n < 0)
        {
            return (1.0 / _pow(x, -n));
        }
        else
        {
            return _pow(x, n);
        }
    }
};
int main()
{
    double x;
    int n;
    cin >> x >> n;
    Solution obj;
    cout << obj.myPow(x, n) << endl;
    return 0;
}