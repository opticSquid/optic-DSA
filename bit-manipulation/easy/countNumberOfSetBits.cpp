#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int count_bits(int n)
    {
        int count = 0;
        while (n >= 1)
        {
            count += n % 2;

            // n /= 2
            n = n >> 1;
        }
        return count;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution obj;
    cout << obj.count_bits(n) << endl;
    return 0;
}