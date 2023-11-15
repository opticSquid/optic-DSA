#include <bits/stdc++.h>
using namespace std;
void insertionSort(int *arr, int len);
void display(int *arr, int len);
int main()
{
    int arr[] = {9, 7, 5, 3, 1, 0, 2, 4, 6, 8};
    // gives the size as if the arr index is 1 based
    // i.e., for arr it is 10
    int len = sizeof(arr) / sizeof(*arr);
    cout << "Before sorting:" << endl;
    display(arr, len);
    insertionSort(arr, len);
    cout << "After Sorting:" << endl;
    display(arr, len);
    return 0;
}
void insertionSort(int *arr, int len)
{
    // This loops keeps track of the unsorted array
    for (int i = 0; i < len; i++)
    {
        // This loop keeps track of the sorted array
        for (int j = i; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}
void display(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;
}