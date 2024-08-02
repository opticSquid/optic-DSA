#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void insert(int arr[], int i, int n)
    {
        // code here
        if (i == n)
            return;
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
        insert(arr, i + 1, n);
    }

public:
    // Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        insert(arr, 0, n);
    }
};
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution obj;
    cout << "After Sorting..." << endl;
    obj.insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}