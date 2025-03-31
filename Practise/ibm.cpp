#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxImpactedServes(vector<int> priorities, int k)
    {
        map<int, vector<int>> prio;
        for (int i = 0; i < priorities.size(); i++)
        {
            if (prio.find(i) != prio.end())
                prio[i].push_back(i);
            else
                prio[i] = {i};
        }
        vector<int> affected(priorities.size(), 0);
        for (map<int, vector<int>>::iterator i = prio.end(); i != prio.begin(); i--)
        {
            for (int j : i->second)
            {
                affected[j] = 1;
            }
            for (map<int, vector<int>>::iterator j = i; j != prio.begin() && i->first - j->first <= k; j--)
            {
                for (int k : j->second)
                {
                    affected[k] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < priorities.size(); i++)
        {
            if (affected[i] == 1)
                cnt++;
        }
        return cnt;
    }
};
int main()
{
    vector<int> priorities = {5, 21, 10, 20, 11, 12, 20};
    int k = 1;
    Solution obj;
    cout << obj.maxImpactedServes(priorities, k) << endl;
    return 0;
}