#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long totalScore(int hp, vector<int> &damage, vector<int> &requirement)
    {
        int rooms = damage.size();
        long long total_points = 0ll;
        for (int i = 0; i < rooms; i++)
        {
            int cur_health = hp;
            long score = 0l;
            for (int j = i; j < rooms; j++)
            {
                cur_health -= damage[j];
                if (cur_health >= requirement[j])
                {
                    score++;
                }
            }
            total_points += score;
        }
        return total_points;
    }
};
int main()
{
    Solution obj;
    vector<int> damage = {3, 6, 7};
    vector<int> requirement = {4, 2, 5};
    assert(obj.totalScore(11, damage, requirement) == 3);
    return 0;
}