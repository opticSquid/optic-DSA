#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        for (char c : s)
        {
            mp[c]++;
        }
        auto cmp = [](const pair<char, int> &a, const pair<char, int> &b)
        {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        for (const auto &x : mp)
        {
            pq.push(make_pair(x.first, x.second));
        }
        string res = "";
        while (!pq.empty())
        {
            pair<char, int> top = pq.top();
            pq.pop();
            res.append(top.second, top.first);
        }
        return res;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.frequencySort(s) << endl;
    return 0;
}