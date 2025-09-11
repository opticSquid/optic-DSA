#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(int i, int j, string &w1, string &w2, vector<vector<int>> &ops)
    {
        if (i < 0)
        {
            return j + 1;
        }
        else if (j < 0)
        {
            return i + 1;
        }
        else if (ops[i][j] != -1)
        {
            return ops[i][j];
        }
        else if (w1[i] == w2[j])
        {
            return f(i - 1, j - 1, w1, w2, ops);
        }
        else
        {
            int ins = f(i, j - 1, w1, w2, ops);
            int del = f(i - 1, j, w1, w2, ops);
            int rep = f(i - 1, j - 1, w1, w2, ops);
            return 1 + min(ins, min(del, rep));
        }
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> ops(n, vector<int>(m, -1));
        return f(n - 1, m - 1, word1, word2, ops);
    }
};
int main()
{
    Solution obj;
    return 0;
}