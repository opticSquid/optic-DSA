#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList)
    {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end())
        {
            return 0;
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty())
        {
            auto [w, cnt] = q.front();
            q.pop();
            if (w == endWord)
            {
                return cnt;
            }
            for (int i = 0; i < w.size(); i++)
            {
                char oc = w[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    w[i] = c;
                    if (words.find(w) != words.end())
                    {
                        words.erase(w);
                        q.push({w, cnt + 1});
                    }
                }
                w[i] = oc;
            }
        }
        return 0;
    }
};
int main()
{
    Solution obj;
    return 0;
}