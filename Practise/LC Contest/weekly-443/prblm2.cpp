#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    const int BASE = 31;
    const int MOD = 1e9 + 7;
    string reverseString(string t)
    {
        string temp = "";
        int left = 0, right = t.size() - 1;
        while (left <= right)
        {
            temp += t[right];
            right--;
        }
        return temp;
    }
    int countRepeatedSubstring(const string &s, int length)
    {
        if (length == 0)
            return 0;

        unordered_map<long long, int> hashCount; // Hash -> frequency
        long long hashValue = 0, basePower = 1;

        // Compute hash for the first 'length' characters
        for (int i = 0; i < length; i++)
        {
            hashValue = (hashValue * BASE + s[i]) % MOD;
            if (i > 0)
                basePower = (basePower * BASE) % MOD;
        }

        hashCount[hashValue]++;

        // Sliding window to compute hashes of all substrings of length 'length'
        for (int i = 1; i <= s.size() - length; i++)
        {
            // Rolling hash update
            hashValue = (hashValue - s[i - 1] * basePower % MOD + MOD) % MOD;
            hashValue = (hashValue * BASE + s[i + length - 1]) % MOD;

            hashCount[hashValue]++;
        }

        // Find the maximum occurrence of any substring of this length
        int maxOccurrences = 0;
        for (const auto &entry : hashCount)
        {
            maxOccurrences = max(maxOccurrences, entry.second);
        }

        return maxOccurrences > 1 ? maxOccurrences : 0; // Only count if repeated
    }

public:
    int longestPalindrome(string s, string t)
    {
        s = s + reverseString(t);
        int left = 1, right = s.size() - 1, maxLength = 0, occurrences = 0;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int count = countRepeatedSubstring(s, mid);

            if (count > 1)
            { // A valid repeating substring found
                maxLength = mid;
                occurrences = count; // Store the count of the most repeated substring
                left = mid + 1;      // Try a longer substring
            }
            else
            {
                right = mid - 1; // Reduce search space
            }
        }
        return maxLength == 1 ? maxLength * occurrences : maxLength * occurrences + 1;
    }
};
int main()
{
    string s = "b";
    string t = "aaa";
    Solution obj;
    cout << obj.longestPalindrome(s, t) << endl;
    return 0;
}