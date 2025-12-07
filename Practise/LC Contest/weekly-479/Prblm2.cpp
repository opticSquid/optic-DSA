#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool isPrime(const int &n)
    {
        const long sqr = (long)n * n;
        for (int i = 2; i * i < sqr; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }

public:
    int largestPrime(int n)
    {
        int sum = 0, res = 0;
        for (int i = 2; sum <= n; i++)
        {
            if (isPrime(sum))
            {
                res = max(res, sum);
            }
            if (isPrime(i))
            {
                sum += i;
            }
        }
        return res;
    }
};
int main()
{
    Solution obj;
    assert(obj.largestPrime(20) == 17);
    assert(obj.largestPrime(2) == 2);
    return 0;
}