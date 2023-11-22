#include <bits/stdc++.h>
using namespace std;
bool canSortNonAdjuscent(int arr[], int n)
{
    // Check for already sorted or already unsortable cases
    if (is_sorted(arr, arr + n))
    {
        return true;
    }
    if (n <= 2 && arr[0] > arr[n - 1])
    {
        return false;
    }

    // Array is not sorted so, Iterate from the beginning, assuming ascending order
    for (int i = 0; i < n; i++)
    {
        // If this element violates the assumption
        if (arr[i] < arr[i - 1])
        {
            // Starting from 0 till i-j>1  i.e., i=i-2 (non-adjacent), look for a larger element
            // look left
            for (int j = 0; i - j > 1; j++)
            {
                if (arr[j] > arr[i])
                {
                    // swap out of place elements
                    swap(arr[j], arr[i]);
                    // check if the array is sorted now
                    if (is_sorted(arr, arr + n))
                    {
                        return true;
                    }
                }
            }
        }
    }

    // Reached the end and could not sort without adjuscent swaps so, not sortable
    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        if (canSortNonAdjuscent(arr, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}