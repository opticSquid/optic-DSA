#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        // if the sum of the whole array is even that is the max length
        if (sum % 2 == 0)
        {
            cout << n << endl;
            continue;
        }
        // if the sum is odd to make it even,
        // remove one odd element from starting or end
        int i = 0, j = n - 1;
        while (arr[i] % 2 == 0)
        {
            i++;
        }
        while (arr[j] % 2 == 0)
        {
            j--;
        }
        // you can either remove
        // first i+1 elements
        int left = i + 1;
        // last n-j elements
        int right = n - j;
        // compare which ever gives the largest subarray length
        cout << max(n - left, n - right) << endl;
    }
    return 0;
}