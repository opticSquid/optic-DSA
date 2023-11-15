#include <bits/stdc++.h>
using namespace std;
void display(int arr[], int len);
void quickSort(int arr[], int low, int high);
int partitionIndex(int arr[], int low, int high);
int main()
{
    int arr[] = {9, 7, 5, 3, 1, 0, 2, 8, 4, 6};
    cout << "Before sorting" << endl;
    int low = 0, high = (sizeof(arr) / sizeof(arr[0])) - 1;
    display(arr, high);
    quickSort(arr, low, high);
    cout << "After Sorting" << endl;
    display(arr, high);
}
void quickSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    cout << "low: " << low << ", high: " << high << endl;
    cout << "arr[low]: " << arr[low] << ", arr[high]: " << arr[high] << endl;
    cout << "before modification..." << endl;
    display(arr, high);
    int pIndex = partitionIndex(arr, low, high);
    cout << "After modification..." << endl;
    display(arr, high);
    quickSort(arr, low, pIndex - 1);
    quickSort(arr, pIndex + 1, high);
}
int partitionIndex(int arr[], int low, int high)
{
    int pivot = arr[low];
    cout << "pivot: " << pivot << ", arr[low]: " << arr[low] << endl;
    int i = low, j = high;
    while (i < j)
    {
        cout << "looping through..." << endl;
        cout << "i: " << i << ", j: " << j << endl;
        while (arr[i] <= pivot && i <= high - 1)
        {
            cout << "i: " << i << ", arr[i]: " << arr[i] << endl;
            cout << "i LTOET pivot... increasing i by +1" << endl;
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            cout << "j: " << j << ", arr[j]: " << arr[j] << endl;
            cout << "j GT pivot... decreasing j by -1" << endl;
            j--;
        }
        // swap only if i has not crossed j
        if (i < j)
        {
            cout << "internally swapping i: " << i << ", j: " << j << endl;
            cout << "i.e., arr[i]: " << arr[i] << " with arr[j]: " << arr[j] << endl;
            swap(arr[i], arr[j]);
            cout << "After swapping internally..." << endl;
            display(arr, high);
        }
    }
    cout << "pivot: " << pivot << endl;
    cout << "To be swapped..\n"
         << "arr[low]: " << arr[low] << ", j: " << j << ", arr[j]: " << arr[j] << endl;
    swap(arr[low], arr[j]);
    return j;
}
void display(int arr[], int len)
{
    cout << "[ ";
    for (int i = 0; i <= len; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}