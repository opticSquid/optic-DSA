#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool isPrime(long long num)
    {
        if (num <= 1)
            return false;
        if (num == 2)
            return true;
        if ((num & 1) == 0)
            return false;
        for (long long i = 3; i * i <= num; i += 2)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }

public:
    long long sumOfLargestPrimes(const string s)
    {
        unordered_set<long long> primes;
        int n = s.size();

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0')
                continue; // Skip substrings starting with 0
            long long num = 0;
            for (int j = i; j < min(i + 18, n); ++j)
            {
                num = num * 10 + (s[j] - '0');
                if ((num % 2 == 0 && num != 2) || primes.count(num))
                    continue;
                if (isPrime(num))
                {
                    primes.insert(num);
                }
            }
        }

        vector<long long> topPrimes(primes.begin(), primes.end());
        sort(topPrimes.rbegin(), topPrimes.rend()); // Sort in descending order

        long long sum = 0;
        for (int i = 0; i < min(3, (int)topPrimes.size()); ++i)
        {
            sum += topPrimes[i];
        }
        return sum;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.sumOfLargestPrimes(s) << endl;
    return 0;
}