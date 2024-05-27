#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        // {ball, color}
        unordered_map<int, int> balls;
        // {color, Set(ball)}
        unordered_map<int, set<int>> colors;
        vector<int> res;
        for (auto it : queries)
        {
            // consider ball exists
            // if ball exists =>  it already has a color
            if (balls.find(it[0]) != balls.end())
            {
                int prevcolor = balls[it[0]];
                // remove the prev color
                colors[prevcolor].erase(it[0]);
                // if there is no ball left in prev color group
                if (colors[prevcolor].empty())
                {
                    // remove that color group
                    colors.erase(prevcolor);
                }
                // if next color of the ball already exists
                if (colors.find(it[1]) != colors.end())
                {
                    // append ball to color group
                    colors[it[1]].insert(it[0]);
                }
                else
                {
                    // create a new color group with ball in it
                    colors.insert({it[1], {it[0]}});
                }
            }
            // ball new, color repeat
            else if (balls.find(it[0]) == balls.end() && colors.find(it[1]) != colors.end())
            {
                // add ball -> color
                balls.insert({it[0], it[1]});
                // append color -> (..., ball)
                colors[it[1]].insert(it[0]);
            }
            // ball new, color new
            else
            {
                balls.insert({it[0], it[1]});
                colors.insert({it[1], {it[0]}});
            }
            res.push_back(colors.size());
        }
        return res;
    }
};
int main()
{
    int limit = 4;
    vector<vector<int>> q = {{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}};
    Solution obj;
    vector<int> res = obj.queryResults(limit, q);
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}