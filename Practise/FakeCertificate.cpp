#include <bits/stdc++.h>
using namespace std;
int count_consecutive_zeros(char binary_string[], int n)
{
    int max0 = 0;
    int cur0 = 0;
    for (int i = 0; i < n; i++)
    {
        char c = binary_string[i];
        if (c == '0')
        {
            cur0++;
        }
        else
        {
            max0 = std::max(max0, cur0); // Update max after encountering a 1
            cur0 = 0;                    // Reset current count for new sequence
        }
    }
    max0 = max(max0, cur0);
    return max0;
}
int count_ones_loop(char binary_string[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        char c = binary_string[i];
        if (c == '1')
        {
            count++;
        }
    }
    return count;
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        cout << count_consecutive_zeros(s, n) + count_ones_loop(s, n) << endl;
    }
    return 0;
}