#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i : nums)
        {
            pq.push(i);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << obj.findKthLargest(vec, k) << endl;
    return 0;
}