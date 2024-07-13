#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int countDigits(int num)
    {
        if (num == 0)
            return 1; // Handle special case when num is 0

        // Count digits using logarithmic arithmetic
        return static_cast<int>(log10(abs(num))) + 1;
    }
    int extractSubNumber(int num, int startPos, int endPos)
    {
        int numDigits = countDigits(num);
        if (startPos < 1 || endPos > numDigits || startPos > endPos)
        {
            std::cerr << "Invalid positions\n";
            return -1; // Return an error value
        }

        int divisor = pow(10, numDigits - endPos);
        num /= divisor;

        return num % static_cast<int>(pow(10, endPos - startPos + 1));
    }
    bool checkPrefixSuffix(int &x, int &y)
    {
        int len1 = countDigits(x);
        // cout << "x: " << x << ", len x: " << len1 << endl;
        // cout << "y: " << y << ", len y: " << len2 << endl;
        // cout << "prefix y: " << extractSubNumber(y, 1, len1) << endl;
        return x == extractSubNumber(y, 1, len1);
    }

public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        int count = 0;
        for (int j = 0; j < arr2.size(); j++)
        {
            for (int i = 0; i < arr1.size(); i++)
            {
                if (arr1[i] < arr2[j])
                {
                    if (checkPrefixSuffix(arr1[i], arr2[j]))
                    {
                        count++;
                    }
                }
                else if (arr1[i] == arr2[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
    int len, t;
    vector<int> a1, a2;
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> t;
        a1.push_back(t);
    }
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> t;
        a2.push_back(t);
    }
    Solution obj;
    cout << obj.longestCommonPrefix(a1, a2) << endl;
    return 0;
}