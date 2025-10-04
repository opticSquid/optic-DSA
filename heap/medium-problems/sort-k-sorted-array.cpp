#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sort(vector<int> arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        // if k becomes greater than arr size we should not exceed array boundary
        int i = 0;
        while (i < k + 1 && i < arr.size())
        {
            pq.push(arr[i]);
            i++;
        }
        vector<int> sorted;
        sorted.reserve(arr.size());
        while (!pq.empty())
        {
            sorted.push_back(pq.top());
            pq.pop();
            if (i < arr.size())
            {
                pq.push(arr[i]);
                i++;
            }
        }
        return sorted;
    }
};
int main()
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    Solution obj;
    arr = obj.sort(arr, k);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << ".";
        }
    }
    cout << endl;
    return 0;
}