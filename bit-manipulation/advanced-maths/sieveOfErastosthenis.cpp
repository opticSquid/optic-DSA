#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<bool> calc_sieve(int *n)
    {
        vector<bool> arr(*n + 1, true);
        for (int i = 2; i * i < *n; i++)
        {
            if (arr[i] == 1)
            {
                for (int j = i * i; j <= *n; j += i)
                {
                    arr[j] = false;
                }
            }
        }
        return arr;
    }

public:
    int countPrimes(int n)
    {
        if (n < 2)
        {
            return 0;
        }
        vector<bool> sieve = calc_sieve(&n);
        int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            if (sieve[i] == true)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution obj;
    cout << obj.countPrimes(n) << endl;
    return 0;
}