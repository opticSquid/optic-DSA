#include <bits/stdc++.h>
using namespace std;
int calculateSumOfDiffs(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += abs(arr[i] - arr[i + 1]);
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ini_sum = calculateSumOfDiffs(arr, n);
        int max_sum = ini_sum;
        for (int i = 0; i < n; i++)
        {
            int tmp = arr[i];
            arr[i] = 1;
            max_sum = max(calculateSumOfDiffs(arr, n), max_sum);
            arr[i] = k;
            max_sum = max(calculateSumOfDiffs(arr, n), max_sum);
            arr[i] = tmp;
        }
        cout << max_sum << '\n';
    }
    return 0;
}