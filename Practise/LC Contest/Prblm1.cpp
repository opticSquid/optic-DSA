#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int duplicateNumbersXOR(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> hash;
        for (int i : nums)
        {
            if (hash.find(i) != hash.end())
            {
                hash[i]++;
            }
            else
            {
                hash.insert({i, 1});
            }
        }
        int sum = 0;
        for (auto kv : hash)
        {
            if (kv.second > 1)
            {
                sum ^= kv.first;
            }
        }
        return sum;
    }
};
int main()
{
    vector<int> arr = {1, 2, 2, 1};
    Solution obj;
    cout << obj.duplicateNumbersXOR(arr) << endl;
    return 0;
}