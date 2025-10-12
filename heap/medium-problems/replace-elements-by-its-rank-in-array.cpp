#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    vector<int> get_rank_array(const vector<int> &arr)
    {
        priority_queue<int, vector<int>> pq;
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            pq.push(arr[i]);
            mp.insert({arr[i], i});
        }
        vector<int> res(arr.size(), 0);
        while (!pq.empty())
        {
            int k = pq.top();
            pq.pop();
            int size = pq.size();
            int i = mp[k];
            res[i] = size + 1;
        }
        return res;
    }
};
int main()
{
    const vector<int> arr = {15, 13, 14, 11, 12};
    Solution obj;
    vector<int> ranks = obj.get_rank_array(arr);
    for (const int &i : arr)
    {
        cout << i << ", ";
    }
    cout << endl;
    for (const int &i : ranks)
    {
        cout << i << ", ";
    }
    return 0;
}