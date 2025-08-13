#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    struct Info
    {
        int x;
        int y;
        double dist;
        Info(double dist, int x, int y) : dist(dist), x(x), y(y) {}
    };
    struct maxonTop
    {
        bool operator()(const Info *a, const Info *b)
        {
            return a->dist < b->dist;
        }
    };
    struct minonTop
    {
        bool operator()(const Info *a, const Info *b)
        {
            return a->dist > b->dist;
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<Info *, vector<Info *>, minonTop> pq;
        for (auto const &p : points)
        {
            double distance = p[0] * p[0] + p[1] * p[1];
            pq.push(new Info(distance, p[0], p[1]));
        }

        vector<vector<int>> res;
        res.reserve(k);
        while (!pq.empty() && k--)
        {
            const auto &coord = pq.top();
            res.push_back({coord->x, coord->y});
            pq.pop();
        }
        return res;
    }
};
int main()
{
    Solution obj;
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    cout << "[";
    for (auto const &i : obj.kClosest(points, 2))
    {
        cout << "[";
        for (auto const &j : i)
        {
            cout << j << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
    return 0;
}