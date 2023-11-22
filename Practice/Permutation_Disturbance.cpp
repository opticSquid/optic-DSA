#include <bits/stdc++.h>
using namespace std;
int nonMatching(int nums[], int n, int s)
{
    queue<int> res;
    for (int i = s; i < n; i++)
    {
        if (i + 1 == nums[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int nums[n];
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        int nm = nonMatching(nums, n, 0);
        int count = 0;
        while (nm != -1)
        {
            // terminal element
            if (nm != n - 1)
            {
                swap(nums[nm], nums[nm + 1]);
            }
            else
            {
                swap(nums[nm - 1], nums[nm]);
            }
            count++;
            nm = nonMatching(nums, n, nm);
        }
        cout << count << endl;
    }
    return 0;
}
