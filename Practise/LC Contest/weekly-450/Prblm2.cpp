#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int digitSum(int x)
    {
        int s = 0;
        while (x > 0)
        {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> arrWithIdx;
        for (int i = 0; i < n; i++)
        {
            arrWithIdx.emplace_back(nums[i], i);
        }
        sort(arrWithIdx.begin(), arrWithIdx.end(), [&](const pair<int, int> &a, const pair<int, int> &b)
             {
                 int ds1 = digitSum(a.first);
                 int ds2 = digitSum(b.first);
                 if(ds1==ds2)
                 return a.first<b.first;
                 else
                 return ds1<ds2; });
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; ++i)
        {
            if (visited[i] || arrWithIdx[i].second == i)
            {
                continue;
            }
            int cycle_size = 0;
            int j = i;
            while (!visited[j])
            {
                visited[j] = true;
                j = arrWithIdx[j].second;
                ++cycle_size;
            }

            if (cycle_size > 1)
            {
                swaps += cycle_size - 1;
            }
        }
        return swaps;
    }
};
int main()
{
    vector<int> arr = {18, 43, 34, 16};
    Solution obj;
    cout << obj.minSwaps(arr) << endl;
    return 0;
}