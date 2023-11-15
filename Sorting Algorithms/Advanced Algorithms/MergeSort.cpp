#include <bits/stdc++.h>
using namespace std;
void display(int arr[], int len);
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
int main()
{
    int arr[] = {9, 7, 5, 3, 1, 0, 2, 8, 4, 6};
    cout << "Before sorting" << endl;
    int low = 0, high = (sizeof(arr) / sizeof(arr[0])) - 1;
    display(arr, high);
    mergeSort(arr, low, high);
    cout << "After Sorting" << endl;
    display(arr, high);
}
void mergeSort(int arr[], int low, int high)
{
    // cout << "dividing..." << endl;
    // cout << "[ ";
    // for (int i = low; i <= high; i++)
    // {
    //     cout << arr[i] << ", ";
    // }
    // cout << "]" << endl;
    if (low >= high)
    {
        // when there is a single element
        return;
    }
    int mid = (low + high) / 2;
    // left half
    mergeSort(arr, low, mid);
    // right half
    mergeSort(arr, mid + 1, high);
    // cout << "merging..." << endl;
    merge(arr, low, mid, high);
}
void merge(int arr[], int low, int mid, int high)
{
    // cout << "left half:" << endl;
    // cout << "[ ";
    // for (int i = low; i <= mid; i++)
    // {
    //     cout << arr[i] << ", ";
    // }
    // cout << "]" << endl;
    // cout << "right half:" << endl;
    // cout << "[ ";
    // for (int i = mid + 1; i <= high; i++)
    // {
    //     cout << arr[i] << ", ";
    // }
    // cout << "]" << endl;
    int tmp[high];
    int tmp_cursor = 0;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            tmp[tmp_cursor] = arr[left];
            left++;
        }
        else
        {
            tmp[tmp_cursor] = arr[right];
            right++;
        }
        tmp_cursor++;
    }
    // for the left over elements after comparison
    while (left <= mid)
    {
        tmp[tmp_cursor] = arr[left];
        left++;
        tmp_cursor++;
    }
    while (right <= high)
    {
        tmp[tmp_cursor] = arr[right];
        right++;
        tmp_cursor++;
    }
    // cout << "merged..." << endl;
    // cout << "[ ";
    // for (int i = 0; i < tmp_cursor; i++)
    // {
    //     cout << tmp[i] << ", ";
    // }
    // cout << "]" << endl;

    // returning all the elements of tmp to arr
    for (int i = low; i <= high; i++)
    {
        arr[i] = tmp[i - low];
    }
}
void display(int arr[], int len)
{
    for (int i = 0; i <= len; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}
