#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    pair<int, int> find_min_max(vector<int> &v)
    {
        int min_el = INT_MAX;
        int max_el = INT_MIN;
        for (int i : v)
        {
            min_el = min(min_el, i);
            max_el = max(max_el, i);
        }
        return {min_el, max_el};
    }
    bool check_possibility(vector<int> &arr, int day, int m, int k)
    {
        int n = arr.size(); // size of the array
        int cnt = 0;
        int noOfB = 0;
        // count the number of bouquets:
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= day)
            {
                cnt++;
            }
            else
            {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }
    bool check_possibility_myImpl(int day, int k, int m, vector<int> &v)
    {
        int n = v.size();
        vector<int> bloomed(n, 0);
        for (int i = 0; i < n; i++)
        {
            // day to bloom for the flower is <= target day
            // then mark flower as bloomed
            if (v[i] <= day)
            {
                bloomed[i] = 1;
            }
        }
        int count_bukays = 0, curr_adj = 0;
        // check how many bouquets can be made
        // based on how many adjuscent flowers have bloomed
        for (int i : bloomed)
        {
            if (i == 1)
            {
                curr_adj++;
                if (curr_adj == k)
                {
                    count_bukays++;
                    // resetting count
                    // because 1 bouquet is complete
                    curr_adj = 0;
                }
            }
            else
            {
                // resetting count
                // because this flower has not bloomed
                curr_adj = 0;
            }
        }
        // if number of bouquets that can be made
        // is >= target number of bouquets return true else false
        return count_bukays >= m ? true : false;
    }

public:
    int count_number_of_days_required(int adj_flowers, int num_bukays, vector<int> &v)
    {
        int req_flowers = adj_flowers * num_bukays;
        int total_flowers = v.size();
        if (total_flowers < req_flowers)
            return -1;
        pair<int, int> min_max = find_min_max(v);
        while (min_max.first <= min_max.second)
        {
            int mid = (min_max.first + min_max.second) / 2;
            if (check_possibility(v, mid, num_bukays, adj_flowers))
            {
                min_max.second = mid - 1;
            }
            else
            {
                min_max.first = mid + 1;
            }
        }
        return min_max.first;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    int m, k;
    cin >> m >> k;
    Solution obj;
    cout << obj.count_number_of_days_required(k, m, v) << endl;
    return 0;
}