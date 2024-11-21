#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int slidingWindow(string &str, int k)
    {
        int n = str.size(), l = 0, r = 0, ans = 0;
        unordered_map<char, int> mp;
        while (r < n)
        {
            // increase the count of current character in the map
            // basically increasing the window to right 1 char at a time
            mp[str[r]]++;
            // if length of the map becomes greater than k
            // that means current substring contain more distinct characters than k
            while (mp.size() > k)
            {
                // start to decrease the count from the left side of string
                // basically decreasing the window from left 1 char at a time
                mp[str[l]]--;
                if (mp[str[l]] == 0)
                    mp.erase(str[l]);
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }

public:
    int countSubstr(string str, int k)
    {
        if (k == 0)
            return 0;
        // return
        //   (count of substring with "at most k" distinct characters)
        // - (count of substring with "at most k-1" distinct characters)
        return slidingWindow(str, k) - slidingWindow(str, k - 1);
    }
};
int main()
{
    string s;
    int k;
    cin >> s >> k;
    Solution obj;
    cout << obj.countSubstr(s, k) << endl;
    return 0;
}