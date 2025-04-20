#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int count_bits_easy(int n)
    {
        int count = 0;
        while (n >= 1)
        {
            // count  = n % 2;
            count += n & 1;

            // n /= 2
            n = n >> 1;
        }
        return count;
    }
    int count_bits_cmplx(int n)
    {
        int count = 0;
        while (n > 0)
        {
            count++;
            // every time the right most set bit turns to 0;
            // so we loop until all set bits are turned to 0
            n = n & (n - 1);
        }
        return count;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution obj;
    cout << obj.count_bits_cmplx(n) << endl;
    return 0;
}