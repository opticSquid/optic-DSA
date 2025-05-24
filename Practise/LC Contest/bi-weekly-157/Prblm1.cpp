#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool isPrime(long long num)
    {
        if (num <= 1)
        {
            return false;
        }
        else if (num == 2)
        {
            return true;
        }
        else if ((num & 1) == 0)
        {
            return false;
        }
        else
        {
            for (long long i = 3l; i * i <= num; i += 2)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    long long sumOfLargestPrimes(string s)
    {
        set<long long> st;
        int lim = 3;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (((s[i] - '0') & 1) == 0 && s[i] != '2')
            {
                continue;
            }
            for (int j = 0; j <= i; j++)
            {
                long long x = stoll(s.substr(j, i - j + 1));
                if (isPrime(x) && st.find(x) == st.end())
                {
                    st.insert(x);
                }
            }
        }
        long long sum = 0l;
        for (auto it = st.rbegin(); it != st.rend() && lim > 0; ++it)
        {
            sum += *it;
            lim--;
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