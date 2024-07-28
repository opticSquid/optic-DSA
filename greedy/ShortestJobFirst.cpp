#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        // code here
        size_t n = bt.size();
        sort(bt.begin(), bt.end());
        long long wait = 0, currentTime = 0;
        for (int it : bt)
        {
            wait += currentTime;
            currentTime += it;
        }
        return wait / n;
    }
};
int main()
{
    size_t n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    Solution obj;
    cout << obj.solve(vec) << endl;
    return 0;
}