#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool checkPrefixSuffix(string &x, string &y)
    {
        if (x == y.substr(0, x.length()) && x == y.substr(y.length() - x.length(), y.length()))
        {
            return true;
        }
        return false;
    }

public:
    long long countPrefixSuffixPairs(vector<string> &words)
    {
        long long counter = 0;
        for (size_t i = 0; i < words.size() - 1; i++)
        {
            for (size_t j = i + 1; j < words.size(); j++)
            {
                // can not be prefix suffix
                if (words[i].length() > words[j].length())
                    continue;
                else
                {
                    // check both prefix and suffix
                    if (checkPrefixSuffix(words[i], words[j]))
                    {
                        counter++;
                    }
                }
            }
        }
        return counter;
    }
};
int main()
{
    vector<string> inp_array;
    int word_count;
    cin >> word_count;
    string temp;
    for (int i = 0; i < word_count; i++)
    {
        cin >> temp;
        inp_array.push_back(temp);
    }
    Solution obj;
    cout << obj.countPrefixSuffixPairs(inp_array) << endl;
}