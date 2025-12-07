#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    string getBinary(const int n)
    {
        if (n == 0)
            return "0";

        string s = "";
        for (int i = 31; i >= 0; --i)
            s.push_back((n & (1 << i)) ? '1' : '0');

        // Remove leading zeros if desired
        size_t fnz = s.find('1');
        if (fnz != string::npos)
        {
            return s.substr(fnz);
        }
        else
        {
            return "0"; // All zeros
        }
    }

    string cutTrailingZeros(const string &n)
    {
        size_t lnz = n.find_last_not_of('0');
        if (lnz == string::npos)
            return "0";
        return n.substr(0, lnz + 1);
    }

    bool compare(int a, int b)
    {
        string bs_a = cutTrailingZeros(getBinary(a));
        string bs_b = cutTrailingZeros(getBinary(b));
        reverse(bs_a.begin(), bs_a.end());
        reverse(bs_b.begin(), bs_b.end());
        if (bs_a == bs_b)
        {
            return a < b;
        }
        return stoll(bs_a, nullptr, 2) < stoll(bs_b, nullptr, 2);
    }

public:
    vector<int> sortByReflection(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(),
             [&](int a, int b)
             { return compare(a, b); });
        return nums;
    }
};

int main()
{
    vector<int> v = {8, 2};
    Solution obj;
    for (const int &i : obj.sortByReflection(v))
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}