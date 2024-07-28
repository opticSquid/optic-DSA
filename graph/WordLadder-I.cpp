#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        word_set.erase(beginWord);
        if (word_set.find(endWord) == word_set.end())
            return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty())
        {
            pair<string, int> node = q.front();
            q.pop();
            if (node.first == endWord)
                return node.second;
            for (int i = 0; i < node.first.size(); i++)
            {
                char original_char = node.first[i];
                for (char j = 'a'; j <= 'z'; j++)
                {
                    node.first[i] = j;
                    // if the word is present in the word list
                    if (word_set.find(node.first) != word_set.end())
                    {
                        q.push({node.first, node.second + 1});
                        word_set.erase(node.first);
                    }
                }
                node.first[i] = original_char;
            }
        }
        return 0;
    }
};
int main()
{
    Solution obj;
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    int result = obj.ladderLength("hit", "cog", wordList);
    cout << result << endl;
    return 0;
}