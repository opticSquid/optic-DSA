#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    long long removeZeros(long long number)
    {
        std::string s = to_string(number);
        auto end_it = std::remove(s.begin(), s.end(), '0');
        s.erase(end_it, s.end());
        return std::stoll(s);
    }
    bool containsZero(long long number)
    {
        string num_s = to_string(number);
        long long num_len = num_s.size();
        for (int l = 0, r = num_len - 1; l <= r; l++, r--)
        {
            if (num_s[l] == '0' || num_s[r] == '0')
            {
                return true;
            }
        }
        return false;
    }

public:
    long long countDistinct(long long n)
    {
        long long cntr = 1ll;
        for (long long i = 2ll; i <= n; i++)
        {
            if (containsZero(i))
            {
                long long cmprsd = removeZeros(i);
                if (cmprsd < i)
                {
                    continue;
                }
                else
                {
                    cntr++;
                }
            }
            else
            {
                cntr++;
            }
        }
        return cntr;
    }
};
int main()
{
    long long n = 100000000ll;
    Solution obj;
    cout << obj.countDistinct(n) << endl;
    return 0;
}