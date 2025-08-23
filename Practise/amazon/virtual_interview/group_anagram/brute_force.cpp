#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> hash;
        for (const auto &str : strs)
        {
            array<int, 26> count = {0};
            for (const auto &c : str)
            {
                count[c - 'a']++;
            }
            string key;
            for (int num : count)
            {
                // # acts as a delimiter prevents key collisons by making the key unique when creating keys based on numerical values
                key += to_string(num) + "#";
            }
            hash[key].push_back(str);
        }
        vector<vector<string>> res;
        for (const auto &h : hash)
        {
            res.push_back(h.second);
        }
        return res;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }
    cout << "[";
    Solution obj;
    for (const auto &ga : obj.groupAnagrams(strs))
    {
        cout << "[";
        for (const auto &str : ga)
        {
            cout << "\"" << str << "\", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
    return 0;
}