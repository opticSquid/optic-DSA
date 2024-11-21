#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        bool isNegetive = false;
        int n = s.size();
        int digitStart = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ' ')
            {
                digitStart = i;
                break;
            }
        }
        if (s[digitStart] == '-')
        {
            isNegetive = true;
            digitStart++;
        }
        else if (s[digitStart] == '+')
        {
            digitStart++;
        }
        int digitEnd = n;
        for (int i = digitStart; i < n; i++)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                digitEnd = i;
                break;
            }
        }
        long num = 0;
        for (int i = digitStart; i < digitEnd; i++)
        {
            num *= 10;
            num += s[i] - 48;
            if (num > INT_MAX)
            {
                if (isNegetive)
                {
                    return INT_MIN;
                }
                else
                {
                    return INT_MAX;
                }
            }
        }
        if (isNegetive)
        {
            num = num * -1;
        }
        return num;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.myAtoi(s) << endl;
    return 0;
}