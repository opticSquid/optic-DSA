#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int i = 0, j = 0, p = 0, maxP = INT_MIN;
        while (i < arr.size() && j < dep.size())
        {
            if (arr[i] <= dep[j])
            {
                p++;
                i++;
            }
            else
            {
                p--;
                j++;
            }
            maxP = max(maxP, p);
        }
        return maxP;
    }
};
;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), dep(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> dep[i];
    }
    Solution obj;
    cout << obj.findPlatform(arr, dep) << endl;
    return 0;
}