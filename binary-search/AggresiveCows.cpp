#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool can_we_place(vector<int> &stalls, int &n, int &min_distance, int &cows)
    {
        int placed_cows = 1, last = stalls[0];
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - last >= min_distance)
            {
                placed_cows++;
                last = stalls[i];
            }
            if (placed_cows >= cows)
            {
                return true;
            }
        }
        return false;
    }

public:
    int max_of_min_distance(vector<int> &stalls, int num_cows)
    {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int l = 1, r = stalls[n - 1] - stalls[0];
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (can_we_place(stalls, n, mid, num_cows))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> stalls_distance(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stalls_distance[i];
        }
        Solution obj;
        cout << obj.max_of_min_distance(stalls_distance, k) << endl;
    }
    return 0;
}