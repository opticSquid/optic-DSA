#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    vector<int> recoverOrder(vector<int> &order, vector<int> &friends)
    {
        unordered_set<int> fs(friends.begin(), friends.end());
        vector<int> res;
        for (const int &i : order)
        {
            if (fs.find(i) != fs.end())
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}