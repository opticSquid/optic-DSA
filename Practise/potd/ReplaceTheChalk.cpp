#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int binarySearch(vector<long> &arr, int tar)
    {
        int l = 0, r = arr.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] <= tar)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return r;
    }

public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        int n = chalk.size();
        vector<long> prefixSum(n);
        // calculating prefix sum for all the elements in the array
        prefixSum[0] = chalk[0];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + chalk[i];
        }
        long sum = prefixSum[n - 1];
        // calculating remaining chak after all full rotations
        long remainingChalk = k % sum;
        return binarySearch(prefixSum, remainingChalk);
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> chalks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> chalks[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << obj.chalkReplacer(chalks, k) << endl;
    return 0;
}