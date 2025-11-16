#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minLengthAfterRemovals(string s)
    {
        int n = s.size();
        int i = 0;
        int ans = INT_MAX;
        while (i < n)
        {
            int l = i, r = i;
            int a_cnt = 0, b_cnt = 0;
            while (r < n)
            {
                switch (s[r])
                {
                case 'a':
                    a_cnt++;
                    break;
                case 'b':
                    b_cnt++;
                    break;
                default:
                    break;
                }
                if (a_cnt == b_cnt)
                {
                    l = r + 1;
                }
                r++;
            }
            i++;
            ans = min(ans, r - l);
        }
        return ans;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.minLengthAfterRemovals(s) << endl;
    return 0;
}