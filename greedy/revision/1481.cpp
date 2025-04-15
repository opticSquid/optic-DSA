#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> freq;
        for (int i : arr)
        {
            freq[i]++;
        }
        vector<int> hash;
        hash.reserve(freq.size());
        for (const auto &[_, count] : freq)
        {
            hash.push_back(count);
        }
        sort(hash.begin(), hash.end());
        int all_removed = 0;
        for (int i : hash)
        {
            if (k >= i)
            {
                k -= i;
                all_removed++;
            }
            else
            {
                break;
            }
        }
        return hash.size() - all_removed;
    }
};
int main()
{
    vector<int> arr = {5, 5, 4};
    int k = 1;
    Solution obj;
    cout << obj.findLeastNumOfUniqueInts(arr, k) << endl;
    return 0;
}